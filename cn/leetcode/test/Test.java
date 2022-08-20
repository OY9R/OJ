package com.leetcode;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

@Target(ElementType.METHOD)    // 应用于方法上的注解
@Retention(RetentionPolicy.RUNTIME)
public @interface Test {
    String value() default "";
    String input() default "";
    String output() default "";
}
