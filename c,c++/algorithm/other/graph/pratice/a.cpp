
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
	wcx.style=CS_HREDRAW|CS_VREDRAW;	//������ʽ
	wcx.lpfnWndProc=MainWndProc;	//��Ϣ������
	wcx.cbClsExtra=0;	//ָ�������ڴ�����ṹ��ĸ����ֽ���
	wcx.cbWndExtra=0;	//ָ�������ڴ���ʵ���ĸ����ֽ���
	wcx.hInstance=hInstance;	//��ģ���ʵ�����
	wcx.hIcon = LoadIcon (NULL, IDI_APPLICATION);	//ͼ��ľ��
	wcx.hCursor = LoadCursor (NULL, IDC_ARROW);	//���ľ��
	wcx.hbrBackground = (HBRUSH) COLOR_MENU;	//������ˢ�ľ��
	wcx.lpszMenuName = NULL;	//ָ��˵���ָ��
	wcx.lpszClassName="test";	//Ҫע�ᴰ���������
	wcx.hIconSm = LoadIcon( NULL, IDI_WINLOGO );	//�ʹ����������Сͼ��
 
	if (!RegisterClassEx (&wcx))
	{
		return 0;
	}
 
	hwnd = CreateWindowEx (NULL,
		"test",	//֮ǰע��Ĵ�����
		"�����ϵ�ṹ�ۺ�ʵ��", //������
		WS_OVERLAPPED|WS_SYSMENU|WS_VISIBLE,	//������ʽ
		CW_USEDEFAULT,	//���ڴ������ˮƽ��ʼλ��
		CW_USEDEFAULT,	//���ڴ�����Ĵ�ֱ��ʼλ��
		600,	//���ڿ��
		400,	//���ڸ߶�
		HWND_DESKTOP,	//ָ�򱻴������ڵĸ����ڻ������ߴ��ڵľ����HWND_DESKTOPϵͳ�Զ��������йܴ��ڡ�
		NULL,	//�˵����
		hInstance,	//�봰���������ģ��ʵ���ľ��
		NULL);	//ָ��һ��ֵ��ָ�룬��ֵ���ݸ�����WM_CREATE��Ϣ
 
	if (!hwnd)
	{
		return 0;
	}
    
    hwndButton[7] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("�ι���"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        100,20,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
     hwndButton[8] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("201925230107"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        100,50,200,20,hwnd,(HMENU)1, hInstance, NULL
    ); 

    hwndButton[0] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("ʵ��һ�� ����ģʽ"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,20,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
     hwndButton[1] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("ʵ����� ����ģʽ"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,50,200,20,hwnd,(HMENU)1, hInstance, NULL
    ); 
    int add = 50; add+=30;
     hwndButton[2] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("ʵ��һ�� �ӿڱ��"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
    add+=30;
     hwndButton[3] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("ʵ����� �򵥹���"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
	add+=30;
     hwndButton[2] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("ʵ����� ����ģʽ"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
    add+=30;
     hwndButton[4] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("ʵ����� ���󹤳�"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
    add+=30;
     hwndButton[5] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("ʵ������ ������������"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
    add+=30;
     hwndButton[6] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("ʵ������ ���������ࣩ"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
    add+=30;
	hwndButton[6] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("ʵ���ģ� ���ģʽ"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
	//DI��ORMģʽ
	add+=30;
	hwndButton[6] = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("ʵ���壺 DI��ORMģʽ"),
        WS_CHILD|WS_VISIBLE|BS_NOTIFY,
        400,add,200,20,hwnd,(HMENU)1, hInstance, NULL
    );
    add+=30;
   /*  hwndButton = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("ʵ��1�� ����ģʽ"),
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
	case WM_CREATE:	//���ڴ���ʱ�յ�����Ϣ
		break;
	case WM_PAINT:	//���ڱ�����ʱ�յ�����Ϣ
		break;
	case WM_SIZE:	//���ڴ�С�ı�ʱ�մ���Ϣ
		break;
	case WM_NOTIFY:	//ͨ���ɿؼ������丸���ڣ�˵���ؼ����ڽ���ĳ��ڲ���
		break;
	case WM_DESTROY:	//��������ʱ�����ر��յ�����Ϣ
		PostQuitMessage(0);
		break;
	case WM_COMMAND:	//�������룬�˵���
		break;
	default:
		break;		
	}
	//�кܶ���Ϣδ��������Ҫ��Ĭ�ϴ�����Ϣ������������
	return DefWindowProc (hwnd, message, wParam, lParam);
}
