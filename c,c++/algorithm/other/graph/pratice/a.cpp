
#include <windows.h>
 
LRESULT CALLBACK MainWndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
 
HWND hwnd;
HWND hwndEdit,hwndLable;
WNDPROC OldEditProc;
HWND hwndButton[14];
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	MSG messages;
	WNDCLASSEX wcx;
	HWND hwnd;
 
	wcx.cbSize=sizeof(wcx);
	wcx.style=CS_HREDRAW|CS_VREDRAW;	//窗口样式
	wcx.lpfnWndProc=MainWndProc;	//消息处理函数
	wcx.cbClsExtra=0;	//指定紧跟在窗口类结构后的附加字节数
	wcx.cbWndExtra=0;	//指定紧跟在窗口实例的附加字节数
	wcx.hInstance=hInstance;	//本模块的实例句柄
	wcx.hIcon = LoadIcon (NULL, IDI_APPLICATION);	//图标的句柄
	wcx.hCursor = LoadCursor (NULL, IDC_ARROW);	//光标的句柄
	wcx.hbrBackground = (HBRUSH) COLOR_MENU;	//背景画刷的句柄
	wcx.lpszMenuName = NULL;	//指向菜单的指针
	wcx.lpszClassName="test";	//要注册窗口类的类名
	wcx.hIconSm = LoadIcon( NULL, IDI_WINLOGO );	//和窗口类关联的小图标
 
	if (!RegisterClassEx (&wcx))
	{
		return 0;
	}
 
	hwnd = CreateWindowEx (NULL,
		"test",	//之前注册的窗口类
		"软件体系结构综合实验", //窗口名
		WS_OVERLAPPED|WS_SYSMENU|WS_VISIBLE,	//窗口样式
		CW_USEDEFAULT,	//窗口创建后的水平初始位置
		CW_USEDEFAULT,	//窗口创建后的垂直初始位置
		600,	//窗口宽度
		400,	//窗口高度
		HWND_DESKTOP,	//指向被创建窗口的父窗口或所有者窗口的句柄。HWND_DESKTOP系统自定义的最顶层托管窗口。
		NULL,	//菜单句柄
		hInstance,	//与窗口相关联的模块实例的句柄
		NULL);	//指向一个值的指针，该值传递给窗口WM_CREATE消息
 
	if (!hwnd)
	{
		return 0;
	}
    
    hwndButton[7] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("何广生"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        100,20,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
     hwndButton[8] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("201925230107"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        100,50,200,20,hwnd,(HMENU)1, hInstance, NULL
    ); 

    hwndButton[0] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("实验一： 单例模式"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,20,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
     hwndButton[1] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("实验二： 多例模式"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,50,200,20,hwnd,(HMENU)1, hInstance, NULL
    ); 
    int add = 50; add+=30;
     hwndButton[2] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("实验一： 接口编程"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
    add+=30;
     hwndButton[3] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("实验二： 简单工厂"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
	add+=30;
     hwndButton[2] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("实验二： 工厂模式"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
    add+=30;
     hwndButton[4] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("实验二： 抽象工厂"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
    add+=30;
     hwndButton[5] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("实验三： 适配器（对象）"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
    add+=30;
     hwndButton[6] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("实验三： 适配器（类）"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
    add+=30;
	hwndButton[6] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("实验四： 组合模式"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
	//DI、ORM模式
	add+=30;
	hwndButton[6] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("实验五： DI、ORM模式"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
    add+=30;
   /*  hwndButton = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("实验1： 单例模式"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,
    ); */
	ShowWindow (hwnd, nShowCmd);
 
	while (GetMessage (&messages, NULL, 0, 0))
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}
	return messages.wParam;
}
 
LRESULT CALLBACK MainWndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_CREATE:	//窗口创建时收到此消息
		break;
	case WM_PAINT:	//窗口被绘制时收到此消息
		break;
	case WM_SIZE:	//窗口大小改变时收此消息
		break;
	case WM_NOTIFY:	//通常由控件发给其父窗口，说明控件正在进行某项窗口操作
		break;
	case WM_DESTROY:	//窗口销毁时或点击关闭收到此消息
		PostQuitMessage(0);
		break;
	case WM_COMMAND:	//命令输入，菜单项
		break;
	default:
		break;		
	}
	//有很多消息未作处理，需要有默认窗口消息处理函数来处理
	return DefWindowProc (hwnd, message, wParam, lParam);
}
