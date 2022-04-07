#include<windows.h>
#include<stdio.h>
char str[1000];
char cmd[1000]; 
//char hour[10], minute[10];
int num;
int num_text_hour, num_text_minute;
//char num_str[]; 
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, LPSTR lpCmdLine,int nCmdShow)
{
    HWND hWnd;
    MSG Msg;
    WNDCLASS WndClass;
    WndClass.style=CS_HREDRAW|CS_VREDRAW;
    WndClass.lpfnWndProc=WndProc;
    WndClass.cbClsExtra=0;
    WndClass.cbWndExtra=0;
    WndClass.hInstance=hInstance;
    WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
    WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
    WndClass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.lpszMenuName=NULL;
    WndClass.lpszClassName="Hello Win";   //窗口类名
    //注册窗口
    if(!RegisterClass(&WndClass))
    {
        MessageBox(NULL,"窗口注册失败!","Hello Win",0);
        return 0;
    }
    //创建窗口
    hWnd=CreateWindow("Hello Win", "定时关机--junmuzi", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
    //显示窗口
    ShowWindow(hWnd,nCmdShow);   
    //更新窗口
    UpdateWindow(hWnd);
    //进入消息循环：当从应用程序消息队列中捡取的消息是WM_QUIT时，则推出循环
    while(GetMessage(&Msg,NULL,0,0))
    {
      TranslateMessage(&Msg);  //转换键盘消息
      DispatchMessage(&Msg);   //分发消息
    }
    return Msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    HDC hDC;
    PAINTSTRUCT Ps;
    char strEdit_hour[10], strEdit_minute[10];
    static HWND hWndButton_ok, hWndButton_cancel, hWndEdit_hour, hWndEdit_minute;
    switch(message)
    {
      case WM_CREATE:
           hWndEdit_hour = CreateWindow("edit",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER,10,60,100,25,hWnd,NULL,NULL,NULL);
           hWndEdit_minute = CreateWindow("edit",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER,180,60,100,25,hWnd,NULL,NULL,NULL);
           hWndButton_ok = CreateWindow("button","确定",WS_CHILD|WS_VISIBLE|WS_BORDER, 340, 60, 100, 25, hWnd,NULL,NULL,NULL);
           hWndButton_cancel = CreateWindow("button","取消定时关机",WS_CHILD|WS_VISIBLE|WS_BORDER, 460, 60, 100, 25, hWnd,NULL,NULL,NULL);
           return 0;
      case WM_COMMAND:
           if(((HWND)lParam==hWndButton_ok)&&(HIWORD(wParam)==BN_CLICKED))
           //按下按键hWndButton_ok
           {    
                num_text_hour = GetWindowText(hWndEdit_hour,strEdit_hour,10);     //获取编辑框控件hour的内容  
                //sprintf(str,"The result is: %s",strEdit_hour);
                //sprintf(hour, "%s", strEdit_hour); 
                if (num_text_hour == 0) 
                {
                    MessageBox(NULL,"小时不能为空!","错误信息：", MB_OK);
                } 
                num_text_minute = GetWindowText(hWndEdit_minute,strEdit_minute,10);     //获取编辑框控件minute的内容
                if (num_text_minute == 0) 
                {
                    MessageBox(NULL,"分钟不能为空!","错误信息：", MB_OK);
                } 
                if (!((atoi(strEdit_hour) >= 0) && (atoi(strEdit_minute) >= 0) && (atoi(strEdit_minute) <= 60)))
                {
                    MessageBox(NULL,"非法输入（输入的小时必须大于等于0，输入的分钟必须大于等于0,且小于等于60）","错误信息：", MB_OK);
                } 
                if ((num_text_hour != 0) && (num_text_minute != 0) && (atoi(strEdit_hour) >= 0) && (atoi(strEdit_minute) >= 0) && (atoi(strEdit_minute) <= 60))
                { 
                    num = atoi(strEdit_hour) * 3600 + atoi(strEdit_minute) * 60;    //把小时和分钟数转化为多少秒 
                    //itoa(num, num_str, 10); 
                    //sprintf(str,"The result is: %s",strEdit_minute);
                    //sprintf(minute, "%s", strEdit_minute); 
                    //strcat(cmd, str_); 
                    //sprintf(cmd, "shutdown -s -t %s %s %d", strEdit_hour, strEdit_minute, num);
                    sprintf(cmd, "shutdown -s -t %d", num);    // 定时关机命令 
                    sprintf(str, "电脑会在%s小时%s分钟后关机！！！", strEdit_hour, strEdit_minute);
                    system(cmd);     //shutdown the computer. 
                    InvalidateRect(hWnd,NULL,TRUE);
                } 
           }
           if(((HWND)lParam == hWndButton_cancel)&&(HIWORD(wParam) == BN_CLICKED))
           //按下按键hWndButton_cancel
           {    
                sprintf(cmd, "shutdown -a");    //取消定时关机 
                sprintf(str, "电脑定时关机被取消！！！");
                system(cmd);     //cancel ”shutdown the computer“. 
                InvalidateRect(hWnd,NULL,TRUE);
           }  
      case WM_PAINT://设计编辑框
           hDC=BeginPaint(hWnd,&Ps);
           TextOut(hDC,10,10,"请输入你要设置的多长时间后关机（小时和分钟数）：",48);
           TextOut(hDC,120,60,"小时",4);
           TextOut(hDC,290,60,"分钟",4);
           //TextOut(hDC,10,90,str,strlen(str));
           TextOut(hDC,10,90,str,strlen(str));
           EndPaint(hWnd,&Ps);
           return 0;
      case WM_DESTROY:
           PostQuitMessage(0);
           return 0;
    }
    return DefWindowProc(hWnd,message,wParam,lParam);
}
