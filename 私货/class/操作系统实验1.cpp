#include <windows.h>
#include <iostream>
int main(){
    // 从当前进程中提取句柄
    HANDLE hProcessThis = ::GetCurrentProcess();
    // 提取当前进程的ID号
    DWORD dwIdThis = ::GetCurrentProcessId();
    // 获得这一进程所需的操作系统版本
    DWORD dwVerReq = ::GetProcessVersion(dwIdThis);
    WORD wMajorReq = (WORD)(dwVerReq >> 16); //右移16位
    WORD wMinorReq = (WORD)(dwVerReq & 0xffff);
    std::cout << "当前进程标识号: " << dwIdThis << ", 所需的操作系统版本: " << wMajorReq << "." << wMinorReq << std::endl;
    // 设置版本信息的数据结构，以便保存操作系统的版本信息
    OSVERSIONINFOEX osvix;
    ::ZeroMemory(&osvix, sizeof(osvix));
    osvix.dwOSVersionInfoSize = sizeof(osvix);
    // 提取当前操作系统的版本信息
    ::GetVersionEx(reinterpret_cast<LPOSVERSIONINFO>(&osvix));
    std::cout << "当前操作系统版本: " << osvix.dwMajorVersion << "." << osvix.dwMinorVersion << std::endl;
    // 请求内核提供该进程所属的优先权类
    DWORD dwPriority = ::GetPriorityClass(hProcessThis);
    // 发出消息，为用户描述该类
    std::cout << "Current process priority: ";
    switch (dwPriority){
    case HIGH_PRIORITY_CLASS:
        std::cout << "高";break;
    case NORMAL_PRIORITY_CLASS:
        std::cout << "普通";break;
    case IDLE_PRIORITY_CLASS:
        std::cout << "空闲";break;
    case REALTIME_PRIORITY_CLASS:
        std::cout << "实时";break;
    default:
        std::cout << "未知";break;
    }
    std::cout << std::endl;
    getchar(); //仅仅为了让窗口停下来，以便观察

    ::SetPriorityClass(hProcessThis,HIGH_PRIORITY_CLASS);
    // 提取当前进程的ID号
    dwIdThis = ::GetCurrentProcessId();
    std::cout << "当前进程标识号: " << dwIdThis << std::endl;
    // 请求内核提供该进程所属的优先权类
    dwPriority = ::GetPriorityClass(hProcessThis);
    // 发出消息，为用户描述该类
    std::cout << "Current process priority: ";
    switch (dwPriority){
    case HIGH_PRIORITY_CLASS:
        std::cout << "高";break;
    case NORMAL_PRIORITY_CLASS:
        std::cout << "普通";break;
    case IDLE_PRIORITY_CLASS:
        std::cout << "空闲";break;
    case REALTIME_PRIORITY_CLASS:
        std::cout << "实时";break;
    default:
        std::cout << "未知";break;
    }
    std::cout << std::endl;
    return 0;
}