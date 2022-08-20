package com.leetcode;

import com.alibaba.fastjson2.JSON;
import com.alibaba.fastjson2.JSONArray;
import org.reflections.Reflections;
import org.reflections.scanners.MethodAnnotationsScanner;
import org.reflections.util.ConfigurationBuilder;

import java.lang.annotation.Annotation;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.*;

public class TestMain {
    private static Map<String, Method> methodMap = new HashMap<>();

    public static void main(String[] args) throws NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException {
        Reflections reflections = new Reflections(new ConfigurationBuilder()
                .forPackages("com.leetcode.july")
                .setScanners(new MethodAnnotationsScanner())
        );
        Set<Method> methods = reflections.getMethodsAnnotatedWith(Test.class);
        StringBuilder print = new StringBuilder();
        for (Method method : methods) {
            Class<?>[] paraTypes = method.getParameterTypes();

            print.append("public ").append(method.getReturnType().getSimpleName()).append(" ").append(method.getName()).append("(");
            for (Class<?> parameterType : paraTypes) {
                print.append(parameterType.getSimpleName()).append(", ");
            }
            print.setLength(print.length() - 2);
            print.append(")");
            //System.out.print(print.toString());
            //print.setLength(0);

            Class<?> declaringClass = method.getDeclaringClass();
            Object instance = declaringClass.getDeclaredConstructor().newInstance();
            Annotation[] annotations = method.getDeclaredAnnotations();
            String value = "";
            for (Annotation annotation : annotations) {
                if (annotation instanceof Test testAnnotation) {
                    value = testAnnotation.value();
                }
            }
            if (value.isBlank()) {
                System.out.println(" {}");
                continue;
            }
            String[] inputs = value.split("[()]");
            List<Object> paraList = new ArrayList<>();
            boolean allPass = true;
            print.append(" {\n");
            for (String input : inputs) {
                if (input.isBlank()) continue;
                if (input.startsWith("*")) {
                    System.out.print("\033[33m" + input + "\033[0m");
                    allPass = false;
                    continue;
                }
                if (!input.startsWith("=")) {
                    JSONArray paras = JSON.parseArray("[" + input + "]");
                    for (int i = 0; i < paraTypes.length; i++) {
                        paraList.add(deserializeInput(paraTypes[i].getSimpleName(), paras.get(i)));
                    }
                    print.append("\t(").append(input).append(")\n");
                } else {
                    String resStr = serializeOutput(method.getReturnType().getSimpleName(), method.invoke(instance, paraList.toArray()));
                    paraList.clear();
                    if (resStr.equals(input.substring(1))) {
                        print.append("\t\t\033[36m= ").append(resStr).append("; [PASS]\033[0m\n");
                    } else {
                        allPass = false;
                        print.append("\t\t\033[31m= ").append(resStr).append("; [FAIL]\033[0m\n");
                        print.append("\t\t\033[36m= ").append(input.substring(1)).append("; \033[0m\n");
                    }
                }
            }
            print.append("}\n");
            if (!allPass) {
                System.out.println(print);
            }
            print.setLength(0);
        }
    }

    private static Object deserializeInput(String parameterType, Object paramObj) {
        if (paramObj instanceof JSONArray listParam) {
            switch (parameterType) {
                case "int[]" -> {
                    int[] res = new int[listParam.size()];
                    for (int i = 0; i < listParam.size(); i++) {
                        if (listParam.get(i) instanceof Integer param) {
                            res[i] = param;
                        }
                    }
                    return res;
                }
                case "char[]" -> {
                    char[] res = new char[listParam.size()];
                    for (int i = 0; i < listParam.size(); i++) {
                        if (listParam.get(i) instanceof String param) {
                            param.getChars(0,1,res,i);
                        }
                    }
                    return res;
                }
                case "int[][]" -> {
                    int[][] res = new int[listParam.size()][];
                    for (int i = 0; i < listParam.size(); i++) {
                        res[i] = (int[]) deserializeInput("int[]", listParam.get(i));
                    }
                    return res;
                }
                case "ListNode" -> {
                    ListNode res = new ListNode(0, null);
                    ListNode node = res;
                    for (Object o : listParam) {
                        if (o instanceof Integer param) {
                            node.next = new ListNode(param, null);
                            node = node.next;
                        }
                    }
                    return res.next;
                }
                case "TreeNode" -> {
                    if (listParam.get(0) == null) return null;
                    List<TreeNode> query = new LinkedList<>();
                    TreeNode root = new TreeNode((Integer)listParam.get(0));
                    TreeNode node = root;
                    for (int i = 1; i < listParam.size(); i++) {
                        if (node == null) {
                            i++;
                            node = query.remove(0);
                            continue;
                        }
                        if (listParam.get(i) instanceof Integer param) {
                            if (i % 2 == 1) {
                                node.left = new TreeNode(param);
                                query.add(node.left);
                            } else if (i % 2 == 0) {
                                node.right = new TreeNode(param);
                                query.add(node.right);
                                node = query.remove(0);
                            }
                        } else if (listParam.get(i) == null) {
                            if (i % 2 == 1) {
                                node.left = null;
                                query.add(null);
                            } else if (i % 2 == 0) {
                                node.right = null;
                                query.add(null);
                                node = query.remove(0);
                            }
                        }
                    }
                    return root;
                }
                default -> throw new IllegalStateException("Unexpected value: " + parameterType);
            }
        }
        return paramObj;
    }

    private static String serializeOutput(String returnType, Object theReturn) {
        switch (returnType) {
            case "ListNode" -> {
                if (theReturn instanceof ListNode node) {
                    List<Integer> list = new ArrayList<>();
                    while (node != null) {
                        list.add(node.val);
                        node = node.next;
                    }
                    return JSON.toJSONString(list);
                }
            }
            case "TreeNode" -> {
                if (theReturn instanceof TreeNode node) {
                    List<TreeNode> query = new LinkedList<>();
                    List<Integer> list = new ArrayList<>();
                    list.add(node.val);
                     do {
                        if (node.left != null) {
                            list.add(node.left.val);
                            query.add(node.left);
                        } else {
                            list.add(null);
                        }
                        if (node.right != null) {
                            list.add(node.right.val);
                            query.add(node.right);
                        } else {
                            list.add(null);
                        }
                        node = query.remove(0);
                    } while (!query.isEmpty());
                    return JSON.toJSONString(list);
                }
            }
            default -> {return JSON.toJSONString(theReturn);}
        }
        throw new IllegalStateException("Unexpected value: " + returnType);
    }
}
