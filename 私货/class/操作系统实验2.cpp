#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <Psapi.h> //如果找不到头文件，可以改用VS2010或更高版本。
#pragma comment(lib, "psapi.lib")
// 创建函数GetKernelModePercentage，计算进程内核模式消耗的时间百分比
// 参数：ftKernel 内核模式时间 ftUser用户模式时间
DWORD GetKernelModePercentage(const FILETIME &ftKernel, const FILETIME &ftUser){
    // 将FILETIME结构转化为64位整数
    ULONGLONG qwKernel = (((ULONGLONG)ftKernel.dwHighDateTime) << 32) + ftKernel.dwLowDateTime;
    ULONGLONG qwUser = (((ULONGLONG)ftUser.dwHighDateTime) << 32) + ftUser.dwLowDateTime;
    // 将消耗时间相加，然后计算消耗在内核模式下的时间百分比
    ULONGLONG qwTotal = qwKernel + qwUser;
    if (qwTotal != 0){
        DWORD dwPct = (DWORD)(((ULONGLONG)100 * qwKernel) / qwTotal);
        return (dwPct);
    }else return 0;
}
// 获取当前系统运行的进程，并显示相关的进程信息
int main(){
    // 对当前系统中运行的进程获取“快照”
    HANDLE hSnapshot = ::CreateToolhelp32Snapshot(
        TH32CS_SNAPPROCESS, // 在快照中包含所有的系统进程
        0);                 // 需要获取的进程号，如果是全部进程，则可以设置为0
    // 初始化过程入口
    PROCESSENTRY32 pe;
    ::ZeroMemory(&pe, sizeof(pe));
    pe.dwSize = sizeof(pe);
    BOOL bMore = ::Process32First(hSnapshot, &pe);
    int pcount = 0; //进程计数器
    while (bMore){
        pcount++;
        // 打开用于读取的进程
        HANDLE hProcess = ::OpenProcess(
            PROCESS_QUERY_INFORMATION, // 指明要得到信息
            FALSE,                     // 不必继承这一句柄
            pe.th32ProcessID
        );
        // 要打开的进程的ID
        if (hProcess != NULL){
            // 找出进程的时间
            FILETIME ftCreation, ftKernelMode, ftUserMode, ftExit;
            ::GetProcessTimes(
                hProcess,      // 所感兴趣的进程
                &ftCreation,   // 进程的启动时间
                &ftExit,       // 结束时间 (如果有的话)
                &ftKernelMode, // 在内核模式下消耗的时间
                &ftUserMode    // 在用户模式下消耗的时间
            );
            //内核模式时间64位整数
            ULONGLONG Kernel = (((ULONGLONG)ftKernelMode.dwHighDateTime) << 32) + ftKernelMode.dwLowDateTime;
            //用户模式时间 64位整数
            ULONGLONG User = (((ULONGLONG)ftUserMode.dwHighDateTime) << 32) + ftUserMode.dwLowDateTime;
            // 计算内核模式消耗的时间百分比
            DWORD dwPctKernel = ::GetKernelModePercentage(
                ftKernelMode, // 在内核模式上消耗的时间
                ftUserMode    // 在用户模式下消耗的时间
            );
            //提取进程的内存使用情况
            PROCESS_MEMORY_COUNTERS memoryinfo;
            ::GetProcessMemoryInfo(hProcess, &memoryinfo, sizeof(memoryinfo));
            // 向用户显示进程的某些信息
            TCHAR szImagePath[MAX_PATH];
            GetProcessImageFileName(
                hProcess, //进程句柄
                szImagePath,//包括设备名的完整路径程序文件
                sizeof(szImagePath) //存放结果的变量的字节数
            );
            std::cout << "进程号: " << pe.th32ProcessID
                      << ", 父进程号: " << pe.th32ParentProcessID
                      << ", 进程名:" << pe.szExeFile //若进程名输出有问题, 可将进程名单独改用其他输出函数，如_tprintf等
                      << ", 进程完整路径: " << szImagePath
                      << "\n物理内存: " << memoryinfo.WorkingSetSize / 1024 << "K"
                      << ",虚拟内存：" << memoryinfo.PagefileUsage / 1024 << "K"
                      << ",用户模式时间：" << User << "ms"
                      << ",内核模式时间：" << Kernel << "ms"
                      << ",内核模式百分比 " << dwPctKernel << "%" << std::endl;
            // 消除句柄
            ::CloseHandle(hProcess);
        }
        // 转向下一个进程
        bMore = ::Process32Next(hSnapshot, &pe);
    }
    std::cout << "系统中运行的进程总数为：" << pcount << std::endl;
    getchar();
    return 0;
}