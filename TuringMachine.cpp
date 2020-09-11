// TuringMachine.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "framework.h"
#include "TuringMachine.h"
#include <Windows.h>
#include <stdio.h>

#define MAX_LOADSTRING 100

// グローバル変数:
HINSTANCE hInst;                                // 現在のインターフェイス
WCHAR szTitle[MAX_LOADSTRING];                  // タイトル バーのテキスト
WCHAR szWindowClass[MAX_LOADSTRING];            // メイン ウィンドウ クラス名
HWND combobox6;

// このコード モジュールに含まれる関数の宣言を転送します:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ここにコードを挿入してください。

    // グローバル文字列を初期化する
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TURINGMACHINE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // アプリケーション初期化の実行:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TURINGMACHINE));

    MSG msg;

    // メイン メッセージ ループ:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  関数: MyRegisterClass()
//
//  目的: ウィンドウ クラスを登録します。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TURINGMACHINE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TURINGMACHINE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}




//
//   関数: InitInstance(HINSTANCE, int)
//
//   目的: インスタンス ハンドルを保存して、メイン ウィンドウを作成します
//
//   コメント:
//
//        この関数で、グローバル変数でインスタンス ハンドルを保存し、
//        メイン プログラム ウィンドウを作成および表示します。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // グローバル変数にインスタンス ハンドルを格納する

   //ウィンドウの初期サイズと位置を指定
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      100, 20, 1400, 800, nullptr, nullptr, hInstance, nullptr);

   HWND hwnd_button1;
   HWND hwnd_button2;
   HWND hwnd_button3;
   HWND hwnd_button4;
   HWND hwnd_button5;
   HWND hwnd_button6;
   HWND run_button;
   HWND step_button;
   
   
   //HWND pause_button;



   hwnd_button1 = CreateWindowW(TEXT("button"), TEXT("#01"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 300, 700, 100, 30, hWnd, (HMENU)0, hInstance, NULL);
   hwnd_button2 = CreateWindowW(TEXT("button"), TEXT("#02"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 420, 700, 100, 30, hWnd, (HMENU)4, hInstance, NULL);
   hwnd_button3 = CreateWindowW(TEXT("button"), TEXT("#03"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 540, 700, 100, 30, hWnd, (HMENU)5, hInstance, NULL);
   hwnd_button4 = CreateWindowW(TEXT("button"), TEXT("#04"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 660, 700, 100, 30, hWnd, (HMENU)6, hInstance, NULL);
   hwnd_button5 = CreateWindowW(TEXT("button"), TEXT("#05"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 780, 700, 100, 30, hWnd, (HMENU)7, hInstance, NULL);
   hwnd_button6 = CreateWindowW(TEXT("button"), TEXT("#06"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 900, 700, 100, 30, hWnd, (HMENU)8, hInstance, NULL);
   
   combobox6 = CreateWindowExW(0, L"COMBOBOX", NULL, CBS_DROPDOWNLIST | WS_CHILD | WS_VISIBLE, 1150, 150, 100, 170, hWnd, (HMENU)9, hInstance, NULL);
   SendMessageW(combobox6, CB_ADDSTRING, NULL, (LPARAM)"1");
   SendMessageW(combobox6, CB_ADDSTRING, NULL, (LPARAM)"2");
   SendMessageW(combobox6, CB_ADDSTRING, NULL, (LPARAM)"3");
   SendMessageW(combobox6, CB_ADDSTRING, NULL, (LPARAM)"4");
   SendMessageW(combobox6, CB_ADDSTRING, NULL, (LPARAM)"5");
   SendMessageW(combobox6, CB_ADDSTRING, NULL, (LPARAM)"6");
   SendMessageW(combobox6, CB_ADDSTRING, NULL, (LPARAM)"7");
   run_button = CreateWindowW(TEXT("button"), TEXT("実行"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 300, 115, 100, 30, hWnd, (HMENU)1, hInstance, NULL);
   step_button = CreateWindowW(TEXT("button"), TEXT("ステップ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 420, 115, 100, 30, hWnd, (HMENU)2, hInstance, NULL);
   //pause_button = CreateWindowW(TEXT("button"), TEXT("強制終了"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 540, 115, 100, 30, hWnd, (HMENU)3, hInstance, NULL);

   

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  関数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: メイン ウィンドウのメッセージを処理します。
//
//  WM_COMMAND  - アプリケーション メニューの処理
//  WM_PAINT    - メイン ウィンドウを描画する
//  WM_DESTROY  - 中止メッセージを表示して戻る
//
//


int set_program = 0;
int machine_01 = 0;
int machine_01_pos = 0;
int tape_01[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int step_counter_01 = 0;
int machine_02 = 0;
int machine_02_pos = 0;
int tape_02[50] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int machine_03 = 0;
int machine_03_pos = 1;
int tape_03[29] = { 3,3,1,0,1,0,4,0,1,0,2,0,4,0,1,0,2,0,4,0,0,0,0,0,0,0,0,0,0 };
int machine_04 = 0;
int machine_04_pos = 0;
int tape_04[37] = { 1,0,1,0,1,0,2,0,1,0,1,0,1,0,1,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int machine_05 = 0;
int machine_05_pos = 0;
int tape_05[24] = { 1,0,1,0,1,0,2,0,1,0,1,0,3,0,0,0,0,0,0,0,0,0,0,0 };
int machine_06 = 0;
int machine_06_pos = 0;
int tape_06[34] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int set_number;
bool run_checker1 = false;
bool run_checker2 = false;
bool run_checker3 = false;
bool run_checker4 = false;
bool run_checker5 = false;
bool run_checker6 = false;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc1 = GetDC(hWnd);
    
    switch (message)
    {   
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            TCHAR program_number[] = TEXT("#01");
            TCHAR program_number2[] = TEXT("#02");
            TCHAR program_number3[] = TEXT("#03");
            TCHAR program_number4[] = TEXT("#04");
            TCHAR program_number5[] = TEXT("#05");
            TCHAR program_number6[] = TEXT("#06");
            TCHAR config_b[] = TEXT("b");
            TCHAR config_b1[] = TEXT("b1");
            TCHAR config_c[] = TEXT("c");
            TCHAR config_c1[] = TEXT("c1");
            TCHAR config_d[] = TEXT("d");
            TCHAR config_d1[] = TEXT("d1");
            TCHAR config_e[] = TEXT("e");
            TCHAR config_e1[] = TEXT("e1");
            TCHAR config_f[] = TEXT("f");
            TCHAR config_f1[] = TEXT("f1");
            TCHAR config_g[] = TEXT("g");
            TCHAR config_g1[] = TEXT("g1");
            TCHAR config_h[] = TEXT("h");
            TCHAR config_h1[] = TEXT("h1");
            TCHAR config_h2[] = TEXT("h2");
            TCHAR config_i[] = TEXT("i");
            TCHAR config_i1[] = TEXT("i1");
            TCHAR config_j[] = TEXT("j");
            TCHAR config_j1[] = TEXT("j1");
            TCHAR config_k[] = TEXT("k");
            TCHAR config_k1[] = TEXT("k1");
            TCHAR config_o[] = TEXT("o");
            TCHAR config_o1[] = TEXT("o1");
            TCHAR config_o2[] = TEXT("o2");
            TCHAR config_o3[] = TEXT("o3");
            TCHAR config_o4[] = TEXT("o4");
            TCHAR config_o5[] = TEXT("o5");
            TCHAR config_o6[] = TEXT("o6");
            TCHAR config_o7[] = TEXT("o7");
            TCHAR config_o8[] = TEXT("o8");
            TCHAR config_o9[] = TEXT("o9");
            TCHAR config_q[] = TEXT("q");
            TCHAR config_q1[] = TEXT("q1");
            TCHAR config_p[] = TEXT("p");
            TCHAR config_p1[] = TEXT("p1");
            TCHAR zero[] = TEXT("0");
            TCHAR one[] = TEXT("1");
            TCHAR e[] = TEXT("e");
            TCHAR x[] = TEXT("x");
            HFONT hFont;
            // 選択されたメニューの解析:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case 0:
                hFont = CreateFont(40, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                SelectObject(hdc1, hFont);
                TextOut(hdc1, 220, 150, program_number, lstrlen(program_number));
                if (run_checker1 == true) {
                    step_counter_01 = 0;
                    machine_01 = 0;
                    machine_01_pos = 0;
                    for (int tape_reload_counter_01 = 0; tape_reload_counter_01 < 20; tape_reload_counter_01++) {
                        tape_01[tape_reload_counter_01] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_01 = 0; circle_counter_01 < 16; circle_counter_01++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_01, 200, 350 + 50 * circle_counter_01, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 300, 430, 1100, 460);
                    run_checker1 = false;
                }
                if (run_checker2 == true) {
                    machine_02 = 0;
                    machine_02_pos = 0;
                    for (int tape_reload_counter_02 = 0; tape_reload_counter_02 < 45; tape_reload_counter_02++) {
                        tape_02[tape_reload_counter_02] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_02 = 0; circle_counter_02 < 16; circle_counter_02++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_02, 200, 350 + 50 * circle_counter_02, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 460);
                    run_checker2 = false;
                }
                if (run_checker3 == true) {
                    machine_03 = 0;
                    machine_03_pos = 1;
                    tape_03[0] = 3;
                    tape_03[1] = 3;
                    tape_03[2] = 1;
                    tape_03[3] = 0;
                    tape_03[4] = 1;
                    tape_03[5] = 0;
                    tape_03[6] = 4;
                    tape_03[7] = 0;
                    tape_03[8] = 1;
                    tape_03[9] = 0;
                    tape_03[10] = 2;
                    tape_03[11] = 0;
                    tape_03[12] = 4;
                    tape_03[13] = 0;
                    tape_03[14] = 1;
                    tape_03[15] = 0;
                    tape_03[16] = 2;
                    tape_03[17] = 0;
                    tape_03[18] = 4;
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_03 = 0; circle_counter_03 < 16; circle_counter_03++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_03, 200, 350 + 50 * circle_counter_03, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker3 = false;
                }
                if (run_checker4 == true) {
                    machine_04 = 0;
                    machine_04_pos = 0;
                    tape_04[0] = 1;
                    tape_04[1] = 0;
                    tape_04[2] = 1;
                    tape_04[3] = 0;
                    tape_04[4] = 1;
                    tape_04[5] = 0;
                    tape_04[6] = 2;
                    tape_04[7] = 0;
                    tape_04[8] = 1;
                    tape_04[9] = 0;
                    tape_04[10] = 1;
                    tape_04[11] = 0;
                    tape_04[12] = 1;
                    tape_04[13] = 0;
                    tape_04[14] = 1;
                    tape_04[15] = 0;
                    tape_04[16] = 3;
                    for (int tape_reload_counter_04 = 17; tape_reload_counter_04 < 32; tape_reload_counter_04++) {
                        tape_04[tape_reload_counter_04] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_04 = 0; circle_counter_04 < 16; circle_counter_04++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_04, 200, 350 + 50 * circle_counter_04, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker4 = false;
                }
                if (run_checker5 == true) {
                    machine_05 = 0;
                    machine_05_pos = 0;
                    tape_05[0] = 1;
                    tape_05[1] = 0;
                    tape_05[2] = 1;
                    tape_05[3] = 0;
                    tape_05[4] = 1;
                    tape_05[5] = 0;
                    tape_05[6] = 2;
                    tape_05[7] = 0;
                    tape_05[8] = 1;
                    tape_05[9] = 0;
                    tape_05[10] = 1;
                    tape_05[11] = 0;
                    tape_05[12] = 3;
                    for (int tape_reload_counter_05 = 13; tape_reload_counter_05 < 15; tape_reload_counter_05++) {
                        tape_05[tape_reload_counter_05] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_05 = 0; circle_counter_05 < 16; circle_counter_05++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_05, 200, 350 + 50 * circle_counter_05, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker5 = false;
                }
                if (run_checker6 == true) {
                    machine_06 = 0;
                    machine_06_pos = 0;
                    for (int tape_reload_counter_06 = 0; tape_reload_counter_06 < 34; tape_reload_counter_06++) {
                        tape_06[tape_reload_counter_06] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_06 = 0; circle_counter_06 < 16; circle_counter_06++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_06, 200, 350 + 50 * circle_counter_06, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker6 = false;
                }
                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                SelectObject(hdc1, hFont);
                TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                set_program = 1;
                break;
            case 4:
                hFont = CreateFont(40, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                SelectObject(hdc1, hFont);
                TextOut(hdc1, 220, 150, program_number2, lstrlen(program_number2));
                if (run_checker1 == true) {
                    step_counter_01 = 0;
                    machine_01 = 0;
                    machine_01_pos = 0;
                    for (int tape_reload_counter_01 = 0; tape_reload_counter_01 < 20; tape_reload_counter_01++) {
                        tape_01[tape_reload_counter_01] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_01 = 0; circle_counter_01 < 16; circle_counter_01++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_01, 200, 350 + 50 * circle_counter_01, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 300, 430, 1100, 460);
                    run_checker1 = false;
                }
                if (run_checker2 == true) {
                    machine_02 = 0;
                    machine_02_pos = 0;
                    for (int tape_reload_counter_02 = 0; tape_reload_counter_02 < 45; tape_reload_counter_02++) {
                        tape_02[tape_reload_counter_02] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_02 = 0; circle_counter_02 < 16; circle_counter_02++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_02, 200, 350 + 50 * circle_counter_02, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 460);
                    run_checker2 = false;
                }
                if (run_checker3 == true) {
                    machine_03 = 0;
                    machine_03_pos = 1;
                    tape_03[0] = 3;
                    tape_03[1] = 3;
                    tape_03[2] = 1;
                    tape_03[3] = 0;
                    tape_03[4] = 1;
                    tape_03[5] = 0;
                    tape_03[6] = 4;
                    tape_03[7] = 0;
                    tape_03[8] = 1;
                    tape_03[9] = 0;
                    tape_03[10] = 2;
                    tape_03[11] = 0;
                    tape_03[12] = 4;
                    tape_03[13] = 0;
                    tape_03[14] = 1;
                    tape_03[15] = 0;
                    tape_03[16] = 2;
                    tape_03[17] = 0;
                    tape_03[18] = 4;
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_03 = 0; circle_counter_03 < 16; circle_counter_03++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_03, 200, 350 + 50 * circle_counter_03, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker3 = false;
                }
                if (run_checker4 == true) {
                    machine_04 = 0;
                    machine_04_pos = 0;
                    tape_04[0] = 1;
                    tape_04[1] = 0;
                    tape_04[2] = 1;
                    tape_04[3] = 0;
                    tape_04[4] = 1;
                    tape_04[5] = 0;
                    tape_04[6] = 2;
                    tape_04[7] = 0;
                    tape_04[8] = 1;
                    tape_04[9] = 0;
                    tape_04[10] = 1;
                    tape_04[11] = 0;
                    tape_04[12] = 1;
                    tape_04[13] = 0;
                    tape_04[14] = 1;
                    tape_04[15] = 0;
                    tape_04[16] = 3;
                    for (int tape_reload_counter_04 = 17; tape_reload_counter_04 < 32; tape_reload_counter_04++) {
                        tape_04[tape_reload_counter_04] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_04 = 0; circle_counter_04 < 16; circle_counter_04++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_04, 200, 350 + 50 * circle_counter_04, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker4 = false;
                }
                if (run_checker5 == true) {
                    machine_05 = 0;
                    machine_05_pos = 0;
                    tape_05[0] = 1;
                    tape_05[1] = 0;
                    tape_05[2] = 1;
                    tape_05[3] = 0;
                    tape_05[4] = 1;
                    tape_05[5] = 0;
                    tape_05[6] = 2;
                    tape_05[7] = 0;
                    tape_05[8] = 1;
                    tape_05[9] = 0;
                    tape_05[10] = 1;
                    tape_05[11] = 0;
                    tape_05[12] = 3;
                    for (int tape_reload_counter_05 = 13; tape_reload_counter_05 < 15; tape_reload_counter_05++) {
                        tape_05[tape_reload_counter_05] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_05 = 0; circle_counter_05 < 16; circle_counter_05++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_05, 200, 350 + 50 * circle_counter_05, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker5 = false;
                }
                if (run_checker6 == true) {
                    machine_06 = 0;
                    machine_06_pos = 0;
                    for (int tape_reload_counter_06 = 0; tape_reload_counter_06 < 34; tape_reload_counter_06++) {
                        tape_06[tape_reload_counter_06] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_06 = 0; circle_counter_06 < 16; circle_counter_06++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_06, 200, 350 + 50 * circle_counter_06, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker6 = false;
                }
                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                SelectObject(hdc1, hFont);
                TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                set_program = 2;
                break;
            case 5:
                hFont = CreateFont(40, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                SelectObject(hdc1, hFont);
                TextOut(hdc1, 220, 150, program_number3, lstrlen(program_number3));
                if (run_checker1 == true) {
                    step_counter_01 = 0;
                    machine_01 = 0;
                    machine_01_pos = 0;
                    for (int tape_reload_counter_01 = 0; tape_reload_counter_01 < 20; tape_reload_counter_01++) {
                        tape_01[tape_reload_counter_01] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_01 = 0; circle_counter_01 < 16; circle_counter_01++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_01, 200, 350 + 50 * circle_counter_01, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 300, 430, 1100, 460);
                    run_checker1 = false;
                }
                if (run_checker2 == true) {
                    machine_02 = 0;
                    machine_02_pos = 0;
                    for (int tape_reload_counter_02 = 0; tape_reload_counter_02 < 45; tape_reload_counter_02++) {
                        tape_02[tape_reload_counter_02] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_02 = 0; circle_counter_02 < 16; circle_counter_02++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_02, 200, 350 + 50 * circle_counter_02, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 460);
                    run_checker2 = false;
                }
                if (run_checker3 == true) {
                    machine_03 = 0;
                    machine_03_pos = 1;
                    tape_03[0] = 3;
                    tape_03[1] = 3;
                    tape_03[2] = 1;
                    tape_03[3] = 0;
                    tape_03[4] = 1;
                    tape_03[5] = 0;
                    tape_03[6] = 4;
                    tape_03[7] = 0;
                    tape_03[8] = 1;
                    tape_03[9] = 0;
                    tape_03[10] = 2;
                    tape_03[11] = 0;
                    tape_03[12] = 4;
                    tape_03[13] = 0;
                    tape_03[14] = 1;
                    tape_03[15] = 0;
                    tape_03[16] = 2;
                    tape_03[17] = 0;
                    tape_03[18] = 4;
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_03 = 0; circle_counter_03 < 16; circle_counter_03++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_03, 200, 350 + 50 * circle_counter_03, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker3 = false;
                }
                if (run_checker4 == true) {
                    machine_04 = 0;
                    machine_04_pos = 0;
                    tape_04[0] = 1;
                    tape_04[1] = 0;
                    tape_04[2] = 1;
                    tape_04[3] = 0;
                    tape_04[4] = 1;
                    tape_04[5] = 0;
                    tape_04[6] = 2;
                    tape_04[7] = 0;
                    tape_04[8] = 1;
                    tape_04[9] = 0;
                    tape_04[10] = 1;
                    tape_04[11] = 0;
                    tape_04[12] = 1;
                    tape_04[13] = 0;
                    tape_04[14] = 1;
                    tape_04[15] = 0;
                    tape_04[16] = 3;
                    for (int tape_reload_counter_04 = 17; tape_reload_counter_04 < 32; tape_reload_counter_04++) {
                        tape_04[tape_reload_counter_04] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_04 = 0; circle_counter_04 < 16; circle_counter_04++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_04, 200, 350 + 50 * circle_counter_04, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker4 = false;
                }
                if (run_checker5 == true) {
                    machine_05 = 0;
                    machine_05_pos = 0;
                    tape_05[0] = 1;
                    tape_05[1] = 0;
                    tape_05[2] = 1;
                    tape_05[3] = 0;
                    tape_05[4] = 1;
                    tape_05[5] = 0;
                    tape_05[6] = 2;
                    tape_05[7] = 0;
                    tape_05[8] = 1;
                    tape_05[9] = 0;
                    tape_05[10] = 1;
                    tape_05[11] = 0;
                    tape_05[12] = 3;
                    for (int tape_reload_counter_05 = 13; tape_reload_counter_05 < 15; tape_reload_counter_05++) {
                        tape_05[tape_reload_counter_05] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_05 = 0; circle_counter_05 < 16; circle_counter_05++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_05, 200, 350 + 50 * circle_counter_05, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker5 = false;
                }
                if (run_checker6 == true) {
                    machine_06 = 0;
                    machine_06_pos = 0;
                    for (int tape_reload_counter_06 = 0; tape_reload_counter_06 < 34; tape_reload_counter_06++) {
                        tape_06[tape_reload_counter_06] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_06 = 0; circle_counter_06 < 16; circle_counter_06++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_06, 200, 350 + 50 * circle_counter_06, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker6 = false;
                }
                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                SelectObject(hdc1, hFont);
                TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                set_program = 3;
                break;
            case 6:
                hFont = CreateFont(40, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                SelectObject(hdc1, hFont);
                TextOut(hdc1, 220, 150, program_number4, lstrlen(program_number4));
                if (run_checker1 == true) {
                    step_counter_01 = 0;
                    machine_01 = 0;
                    machine_01_pos = 0;
                    for (int tape_reload_counter_01 = 0; tape_reload_counter_01 < 20; tape_reload_counter_01++) {
                        tape_01[tape_reload_counter_01] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_01 = 0; circle_counter_01 < 16; circle_counter_01++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_01, 200, 350 + 50 * circle_counter_01, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 300, 430, 1100, 460);
                    run_checker1 = false;
                }
                if (run_checker2 == true) {
                    machine_02 = 0;
                    machine_02_pos = 0;
                    for (int tape_reload_counter_02 = 0; tape_reload_counter_02 < 45; tape_reload_counter_02++) {
                        tape_02[tape_reload_counter_02] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_02 = 0; circle_counter_02 < 16; circle_counter_02++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_02, 200, 350 + 50 * circle_counter_02, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 460);
                    run_checker2 = false;
                }
                if (run_checker3 == true) {
                    machine_03 = 0;
                    machine_03_pos = 1;
                    tape_03[0] = 3;
                    tape_03[1] = 3;
                    tape_03[2] = 1;
                    tape_03[3] = 0;
                    tape_03[4] = 1;
                    tape_03[5] = 0;
                    tape_03[6] = 4;
                    tape_03[7] = 0;
                    tape_03[8] = 1;
                    tape_03[9] = 0;
                    tape_03[10] = 2;
                    tape_03[11] = 0;
                    tape_03[12] = 4;
                    tape_03[13] = 0;
                    tape_03[14] = 1;
                    tape_03[15] = 0;
                    tape_03[16] = 2;
                    tape_03[17] = 0;
                    tape_03[18] = 4;
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_03 = 0; circle_counter_03 < 16; circle_counter_03++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_03, 200, 350 + 50 * circle_counter_03, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker3 = false;
                }
                if (run_checker4 == true) {
                    machine_04 = 0;
                    machine_04_pos = 0;
                    tape_04[0] = 1;
                    tape_04[1] = 0;
                    tape_04[2] = 1;
                    tape_04[3] = 0;
                    tape_04[4] = 1;
                    tape_04[5] = 0;
                    tape_04[6] = 2;
                    tape_04[7] = 0;
                    tape_04[8] = 1;
                    tape_04[9] = 0;
                    tape_04[10] = 1;
                    tape_04[11] = 0;
                    tape_04[12] = 1;
                    tape_04[13] = 0;
                    tape_04[14] = 1;
                    tape_04[15] = 0;
                    tape_04[16] = 3;
                    for (int tape_reload_counter_04 = 17; tape_reload_counter_04 < 32; tape_reload_counter_04++) {
                        tape_04[tape_reload_counter_04] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_04 = 0; circle_counter_04 < 16; circle_counter_04++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_04, 200, 350 + 50 * circle_counter_04, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker4 = false;
                }
                if (run_checker5 == true) {
                    machine_05 = 0;
                    machine_05_pos = 0;
                    tape_05[0] = 1;
                    tape_05[1] = 0;
                    tape_05[2] = 1;
                    tape_05[3] = 0;
                    tape_05[4] = 1;
                    tape_05[5] = 0;
                    tape_05[6] = 2;
                    tape_05[7] = 0;
                    tape_05[8] = 1;
                    tape_05[9] = 0;
                    tape_05[10] = 1;
                    tape_05[11] = 0;
                    tape_05[12] = 3;
                    for (int tape_reload_counter_05 = 13; tape_reload_counter_05 < 15; tape_reload_counter_05++) {
                        tape_05[tape_reload_counter_05] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_05 = 0; circle_counter_05 < 16; circle_counter_05++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_05, 200, 350 + 50 * circle_counter_05, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker5 = false;
                }
                if (run_checker6 == true) {
                    machine_06 = 0;
                    machine_06_pos = 0;
                    for (int tape_reload_counter_06 = 0; tape_reload_counter_06 < 34; tape_reload_counter_06++) {
                        tape_06[tape_reload_counter_06] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_06 = 0; circle_counter_06 < 16; circle_counter_06++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_06, 200, 350 + 50 * circle_counter_06, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker6 = false;
                }
                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                SelectObject(hdc1, hFont);
                TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                set_program = 4;
                break;
            case 7:
                hFont = CreateFont(40, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                SelectObject(hdc1, hFont);
                TextOut(hdc1, 220, 150, program_number5, lstrlen(program_number5));
                if (run_checker1 == true) {
                    step_counter_01 = 0;
                    machine_01 = 0;
                    machine_01_pos = 0;
                    for (int tape_reload_counter_01 = 0; tape_reload_counter_01 < 20; tape_reload_counter_01++) {
                        tape_01[tape_reload_counter_01] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_01 = 0; circle_counter_01 < 16; circle_counter_01++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_01, 200, 350 + 50 * circle_counter_01, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 300, 430, 1100, 460);
                    run_checker1 = false;
                }
                if (run_checker2 == true) {
                    machine_02 = 0;
                    machine_02_pos = 0;
                    for (int tape_reload_counter_02 = 0; tape_reload_counter_02 < 45; tape_reload_counter_02++) {
                        tape_02[tape_reload_counter_02] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_02 = 0; circle_counter_02 < 16; circle_counter_02++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_02, 200, 350 + 50 * circle_counter_02, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 460);
                    run_checker2 = false;
                }
                if (run_checker3 == true) {
                    machine_03 = 0;
                    machine_03_pos = 1;
                    tape_03[0] = 3;
                    tape_03[1] = 3;
                    tape_03[2] = 1;
                    tape_03[3] = 0;
                    tape_03[4] = 1;
                    tape_03[5] = 0;
                    tape_03[6] = 4;
                    tape_03[7] = 0;
                    tape_03[8] = 1;
                    tape_03[9] = 0;
                    tape_03[10] = 2;
                    tape_03[11] = 0;
                    tape_03[12] = 4;
                    tape_03[13] = 0;
                    tape_03[14] = 1;
                    tape_03[15] = 0;
                    tape_03[16] = 2;
                    tape_03[17] = 0;
                    tape_03[18] = 4;
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_03 = 0; circle_counter_03 < 16; circle_counter_03++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_03, 200, 350 + 50 * circle_counter_03, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker3 = false;
                }
                if (run_checker4 == true) {
                    machine_04 = 0;
                    machine_04_pos = 0;
                    tape_04[0] = 1;
                    tape_04[1] = 0;
                    tape_04[2] = 1;
                    tape_04[3] = 0;
                    tape_04[4] = 1;
                    tape_04[5] = 0;
                    tape_04[6] = 2;
                    tape_04[7] = 0;
                    tape_04[8] = 1;
                    tape_04[9] = 0;
                    tape_04[10] = 1;
                    tape_04[11] = 0;
                    tape_04[12] = 1;
                    tape_04[13] = 0;
                    tape_04[14] = 1;
                    tape_04[15] = 0;
                    tape_04[16] = 3;
                    for (int tape_reload_counter_04 = 17; tape_reload_counter_04 < 32; tape_reload_counter_04++) {
                        tape_04[tape_reload_counter_04] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_04 = 0; circle_counter_04 < 16; circle_counter_04++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_04, 200, 350 + 50 * circle_counter_04, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker4 = false;
                }
                if (run_checker5 == true) {
                    machine_05 = 0;
                    machine_05_pos = 0;
                    tape_05[0] = 1;
                    tape_05[1] = 0;
                    tape_05[2] = 1;
                    tape_05[3] = 0;
                    tape_05[4] = 1;
                    tape_05[5] = 0;
                    tape_05[6] = 2;
                    tape_05[7] = 0;
                    tape_05[8] = 1;
                    tape_05[9] = 0;
                    tape_05[10] = 1;
                    tape_05[11] = 0;
                    tape_05[12] = 3;
                    for (int tape_reload_counter_05 = 13; tape_reload_counter_05 < 15; tape_reload_counter_05++) {
                        tape_05[tape_reload_counter_05] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_05 = 0; circle_counter_05 < 16; circle_counter_05++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_05, 200, 350 + 50 * circle_counter_05, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker5 = false;
                }
                if (run_checker6 == true) {
                    machine_06 = 0;
                    machine_06_pos = 0;
                    for (int tape_reload_counter_06 = 0; tape_reload_counter_06 < 34; tape_reload_counter_06++) {
                        tape_06[tape_reload_counter_06] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_06 = 0; circle_counter_06 < 16; circle_counter_06++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_06, 200, 350 + 50 * circle_counter_06, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker6 = false;
                }
                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                SelectObject(hdc1, hFont);
                TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                set_program = 5;
                break;
            case 8:
                hFont = CreateFont(40, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                SelectObject(hdc1, hFont);
                TextOut(hdc1, 220, 150, program_number6, lstrlen(program_number6));
                if (run_checker1 == true) {
                    step_counter_01 = 0;
                    machine_01 = 0;
                    machine_01_pos = 0;
                    for (int tape_reload_counter_01 = 0; tape_reload_counter_01 < 20; tape_reload_counter_01++) {
                        tape_01[tape_reload_counter_01] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_01 = 0; circle_counter_01 < 16; circle_counter_01++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_01, 200, 350 + 50 * circle_counter_01, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 300, 430, 1100, 460);
                    run_checker1 = false;
                }
                if (run_checker2 == true) {
                    machine_02 = 0;
                    machine_02_pos = 0;
                    for (int tape_reload_counter_02 = 0; tape_reload_counter_02 < 45; tape_reload_counter_02++) {
                        tape_02[tape_reload_counter_02] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_02 = 0; circle_counter_02 < 16; circle_counter_02++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_02, 200, 350 + 50 * circle_counter_02, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 460);
                    run_checker2 = false;
                }
                if (run_checker3 == true) {
                    machine_03 = 0;
                    machine_03_pos = 1;
                    tape_03[0] = 3;
                    tape_03[1] = 3;
                    tape_03[2] = 1;
                    tape_03[3] = 0;
                    tape_03[4] = 1;
                    tape_03[5] = 0;
                    tape_03[6] = 4;
                    tape_03[7] = 0;
                    tape_03[8] = 1;
                    tape_03[9] = 0;
                    tape_03[10] = 2;
                    tape_03[11] = 0;
                    tape_03[12] = 4;
                    tape_03[13] = 0;
                    tape_03[14] = 1;
                    tape_03[15] = 0;
                    tape_03[16] = 2;
                    tape_03[17] = 0;
                    tape_03[18] = 4;
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_03 = 0; circle_counter_03 < 16; circle_counter_03++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_03, 200, 350 + 50 * circle_counter_03, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker3 = false;
                }
                if (run_checker4 == true) {
                    machine_04 = 0;
                    machine_04_pos = 0;
                    tape_04[0] = 1;
                    tape_04[1] = 0;
                    tape_04[2] = 1;
                    tape_04[3] = 0;
                    tape_04[4] = 1;
                    tape_04[5] = 0;
                    tape_04[6] = 2;
                    tape_04[7] = 0;
                    tape_04[8] = 1;
                    tape_04[9] = 0;
                    tape_04[10] = 1;
                    tape_04[11] = 0;
                    tape_04[12] = 1;
                    tape_04[13] = 0;
                    tape_04[14] = 1;
                    tape_04[15] = 0;
                    tape_04[16] = 3;
                    for (int tape_reload_counter_04 = 17; tape_reload_counter_04 < 32; tape_reload_counter_04++) {
                        tape_04[tape_reload_counter_04] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_04 = 0; circle_counter_04 < 16; circle_counter_04++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_04, 200, 350 + 50 * circle_counter_04, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker4 = false;
                }
                if (run_checker5 == true) {
                    machine_05 = 0;
                    machine_05_pos = 0;
                    tape_05[0] = 1;
                    tape_05[1] = 0;
                    tape_05[2] = 1;
                    tape_05[3] = 0;
                    tape_05[4] = 1;
                    tape_05[5] = 0;
                    tape_05[6] = 2;
                    tape_05[7] = 0;
                    tape_05[8] = 1;
                    tape_05[9] = 0;
                    tape_05[10] = 1;
                    tape_05[11] = 0;
                    tape_05[12] = 3;
                    for (int tape_reload_counter_05 = 13; tape_reload_counter_05 < 15; tape_reload_counter_05++) {
                        tape_05[tape_reload_counter_05] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_05 = 0; circle_counter_05 < 16; circle_counter_05++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_05, 200, 350 + 50 * circle_counter_05, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker5 = false;
                }
                if (run_checker6 == true) {
                    machine_06 = 0;
                    machine_06_pos = 0;
                    for (int tape_reload_counter_06 = 0; tape_reload_counter_06 < 34; tape_reload_counter_06++) {
                        tape_06[tape_reload_counter_06] = 0;
                    }
                    Rectangle(hdc1, 300, 150, 1100, 400);
                    Ellipse(hdc1, 650, 250, 700, 300);
                    for (int circle_counter_06 = 0; circle_counter_06 < 16; circle_counter_06++) {
                        Ellipse(hdc1, 300 + 50 * circle_counter_06, 200, 350 + 50 * circle_counter_06, 250);
                    }
                    HPEN erace_pen = (HPEN)SelectObject(hdc1, GetStockObject(NULL_PEN));
                    Rectangle(hdc1, 200, 430, 1200, 465);
                    run_checker6 = false;
                }
                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                SelectObject(hdc1, hFont);
                TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                set_program = 6;
                break;
            case 1:
                if (set_program == 1) {
                    for (int run_counter_01 = 0; run_counter_01 < 20; run_counter_01++) {
                        Rectangle(hdc1, 300, 150, 1100, 400);
                        Ellipse(hdc1, 650, 250, 700, 300);
                        if (machine_01 == 0) {
                            machine_01 = 1;
                            tape_01[machine_01_pos] = 1;
                            machine_01_pos++;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_c, lstrlen(config_c));
                        }
                        else if (machine_01 == 1) {
                            machine_01 = 2;
                            machine_01_pos++;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_e, lstrlen(config_e));
                        }
                        else if (machine_01 == 2) {
                            machine_01 = 3;
                            tape_01[machine_01_pos] = 2;
                            machine_01_pos++;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_f, lstrlen(config_f));
                        }
                        else {
                            machine_01 = 0;
                            machine_01_pos++;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                        }
                        
                        for (int circle_counter_01 = 0; circle_counter_01 < 16; circle_counter_01++) {
                            Ellipse(hdc1, 300 + 50*circle_counter_01, 200, 350 + 50*circle_counter_01, 250);  
                        }
                        
                        for (int symbol_counter_01 = 0; symbol_counter_01 < 7; symbol_counter_01++) {
                            if (machine_01_pos - 1 - symbol_counter_01 > -1) {
                                if (tape_01[machine_01_pos - 1 - symbol_counter_01] == 1) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 617 - 50 * symbol_counter_01, 210, zero, lstrlen(zero));
                                }
                                if (tape_01[machine_01_pos - 1 - symbol_counter_01] == 2) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 617 - 50 * symbol_counter_01, 210, one, lstrlen(one));
                                }
                            }
                            
                        }
                        UpdateWindow(hWnd);
                        Sleep(500);
                        
                    }

                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                    SelectObject(hdc1, hFont);
                    TextOut(hdc1, 310, 430, TEXT("出力："), lstrlen(TEXT("出力：")));
                    for (int output_counter_01 = 0; output_counter_01 < 20; output_counter_01++) {
                        if (tape_01[output_counter_01] == 0) {
                            TextOut(hdc1, 390 + 20 * output_counter_01, 430, TEXT(" "), lstrlen(TEXT(" ")));
                        }
                        if (tape_01[output_counter_01] == 1) {
                            TextOut(hdc1, 390 + 20 * output_counter_01, 430, TEXT("0"), lstrlen(TEXT("0")));
                        }
                        if (tape_01[output_counter_01] == 2) {
                            TextOut(hdc1, 390 + 20 * output_counter_01, 430, TEXT("1"), lstrlen(TEXT("1")));
                        }
                    }
                    run_checker1 = true;
                }

                if (set_program == 2) {
                    while (machine_02_pos < 44)
                    {
                        Rectangle(hdc1, 300, 150, 1100, 400);
                        Ellipse(hdc1, 650, 250, 700, 300);
                        if (machine_02 == 0) {
                            tape_02[machine_02_pos] = 3;
                            machine_02_pos++;
                            machine_02 = 1;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 660, 258, config_o1, lstrlen(config_o1));
                        }
                        else if (machine_02 == 1) {
                            tape_02[machine_02_pos] = 3;
                            machine_02_pos++;
                            machine_02 = 2;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 660, 258, config_o2, lstrlen(config_o2));
                        }
                        else if (machine_02 == 2) {
                            tape_02[machine_02_pos] = 1;
                            machine_02_pos++;
                            machine_02 = 3;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 660, 258, config_o3, lstrlen(config_o3));
                        }
                        else if (machine_02 == 3) {
                            machine_02_pos++;
                            machine_02 = 4;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 660, 258, config_o4, lstrlen(config_o4));
                        }
                        else if (machine_02 == 4) {
                            tape_02[machine_02_pos] = 1;
                            machine_02_pos = machine_02_pos - 1;
                            machine_02 = 5;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 660, 258, config_o5, lstrlen(config_o5));
                        }
                        else if (machine_02 == 5) {
                            machine_02_pos = machine_02_pos - 1;
                            machine_02 = 6;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_o, lstrlen(config_o));
                        }
                        else if (machine_02 == 6) {
                            if (tape_02[machine_02_pos] == 1) {
                                machine_02 = 10;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_q, lstrlen(config_q));
                            }
                            if (tape_02[machine_02_pos] == 2) {
                                machine_02_pos++;
                                machine_02 = 7;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_o6, lstrlen(config_o6));
                            }
                        }
                        else if (machine_02 == 7) {
                            tape_02[machine_02_pos] = 4;
                            machine_02_pos = machine_02_pos - 1;
                            machine_02 = 8;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 660, 258, config_o7, lstrlen(config_o7));
                        }
                        else if (machine_02 == 8) {
                            machine_02_pos = machine_02_pos - 1;
                            machine_02 = 9;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 660, 258, config_o8, lstrlen(config_o8));
                        }
                        else if (machine_02 == 9) {
                            machine_02_pos = machine_02_pos - 1;
                            machine_02 = 6;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_o, lstrlen(config_o));
                        }
                        else if (machine_02 == 10) {
                            if (tape_02[machine_02_pos] == 1) {
                                machine_02_pos++;
                                machine_02 = 11;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_q1, lstrlen(config_q1));
                            }
                            else if (tape_02[machine_02_pos] == 2) {
                                machine_02_pos++;
                                machine_02 = 11;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_q1, lstrlen(config_q1));
                            }
                            else {
                                tape_02[machine_02_pos] = 2;
                                machine_02_pos = machine_02_pos - 1;
                                machine_02 = 12;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_p, lstrlen(config_p));
                            }
                        }
                        else if (machine_02 == 11) {
                            machine_02_pos++;
                            machine_02 = 10;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_q, lstrlen(config_q));
                        }
                        else if (machine_02 == 12) {
                            if (tape_02[machine_02_pos] == 4) {
                                tape_02[machine_02_pos] = 0;
                                machine_02_pos++;
                                machine_02 = 10;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_q, lstrlen(config_q));
                            }
                            else if (tape_02[machine_02_pos] == 3) {
                                machine_02_pos++;
                                machine_02 = 14;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_f, lstrlen(config_f));
                            }
                            else if (tape_02[machine_02_pos] == 0) {
                                machine_02_pos = machine_02_pos - 1;
                                machine_02 = 13;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_p1, lstrlen(config_p1));
                            }
                        }
                        else if (machine_02 == 13) {
                            machine_02_pos = machine_02_pos - 1;
                            machine_02 = 12;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_p, lstrlen(config_p));
                        }
                        else if (machine_02 == 14) {
                            if (tape_02[machine_02_pos] == 1) {
                                machine_02_pos++;
                                machine_02 = 15;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 664, 258, config_f1, lstrlen(config_f1));
                            }
                            else if (tape_02[machine_02_pos] == 2) {
                                machine_02_pos++;
                                machine_02 = 15;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 664, 258, config_f1, lstrlen(config_f1));
                            }
                            else if (tape_02[machine_02_pos] == 0) {
                                tape_02[machine_02_pos] = 1;
                                machine_02_pos = machine_02_pos - 1;
                                machine_02 = 16;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_o9, lstrlen(config_o9));
                            }
                        }
                        else if (machine_02 == 15) {
                            machine_02_pos++;
                            machine_02 = 14;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_f, lstrlen(config_f));
                        }
                        else if (machine_02 == 16) {
                            machine_02_pos = machine_02_pos - 1;
                            machine_02 = 6;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_o, lstrlen(config_o));
                        }

                        for (int circle_counter_02 = 0; circle_counter_02 < 16; circle_counter_02++) {
                            Ellipse(hdc1, 300 + 50 * circle_counter_02, 200, 350 + 50 * circle_counter_02, 250);
                        }

                        for (int symbol_counter_02 = 0; symbol_counter_02 < 16; symbol_counter_02++) {
                            if (machine_02_pos - 7 + symbol_counter_02 > -1) {
                                if (tape_02[machine_02_pos - 7 + symbol_counter_02] == 1) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_02, 210, zero, lstrlen(zero));
                                }
                                if (tape_02[machine_02_pos - 7 + symbol_counter_02] == 2) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_02, 210, one, lstrlen(one));
                                }
                                if (tape_02[machine_02_pos - 7 + symbol_counter_02] == 3) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_02, 210, e, lstrlen(e));
                                }
                                if (tape_02[machine_02_pos - 7 + symbol_counter_02] == 4) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_02, 210, x, lstrlen(x));
                                }
                            }

                        }
                        UpdateWindow(hWnd);
                        Sleep(500);
                    }
                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                    SelectObject(hdc1, hFont);
                    TextOut(hdc1, 260, 430, TEXT("出力："), lstrlen(TEXT("出力：")));
                    for (int output_counter_02 = 0; output_counter_02 < 44; output_counter_02++) {
                        if (tape_02[output_counter_02] == 0) {
                            TextOut(hdc1, 340 + 20 * output_counter_02, 430, TEXT(" "), lstrlen(TEXT(" ")));
                        }
                        if (tape_02[output_counter_02] == 1) {
                            TextOut(hdc1, 340 + 20 * output_counter_02, 430, TEXT("0"), lstrlen(TEXT("0")));
                        }
                        if (tape_02[output_counter_02] == 2) {
                            TextOut(hdc1, 340 + 20 * output_counter_02, 430, TEXT("1"), lstrlen(TEXT("1")));
                        }
                        if (tape_02[output_counter_02] == 3) {
                            TextOut(hdc1, 340 + 20 * output_counter_02, 430, TEXT("e"), lstrlen(TEXT("e")));
                        }
                        if (tape_02[output_counter_02] == 4) {
                            TextOut(hdc1, 340 + 20 * output_counter_02, 430, TEXT("x"), lstrlen(TEXT("x")));
                        }
                    }
                    run_checker2 = true;
                }

                if (set_program == 3) {
                    while (machine_03 != 4) {
                        Rectangle(hdc1, 300, 150, 1100, 400);
                        Ellipse(hdc1, 650, 250, 700, 300);
                        if (machine_03 == 0) {
                            if (tape_03[machine_03_pos] == 3) {
                                machine_03_pos = machine_03_pos - 1;
                                machine_03 = 1;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_e, lstrlen(config_e));
                            }
                            else {
                                machine_03_pos = machine_03_pos - 1;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_d, lstrlen(config_d));
                            }
                        }
                        else if (machine_03 == 1) {
                            if (tape_03[machine_03_pos] == 4) {
                                machine_03 = 3;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_c, lstrlen(config_c));
                            }
                            else if (tape_03[machine_03_pos] == 0) {
                                machine_03_pos++;
                                machine_03 = 2;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_f, lstrlen(config_f));
                            }
                            else {
                                machine_03_pos++;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_e, lstrlen(config_e));
                            }
                        }
                        else if (machine_03 == 2) {
                            if (tape_03[machine_03_pos] == 4) {
                                machine_03 = 3;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_c, lstrlen(config_c));
                            }
                            else if (tape_03[machine_03_pos] == 0) {
                                machine_03_pos++;
                                machine_03 = 4;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                            }
                            else {
                                machine_03_pos++;
                                machine_03 = 1;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_e, lstrlen(config_e));
                            }
                        }
                        else if (machine_03 == 3) {
                            tape_03[machine_03_pos] = 5;
                            machine_03 = 0;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_d, lstrlen(config_d));
                        }

                        for (int circle_counter_03 = 0; circle_counter_03 < 16; circle_counter_03++) {
                            Ellipse(hdc1, 300 + 50 * circle_counter_03, 200, 350 + 50 * circle_counter_03, 250);
                        }

                        for (int symbol_counter_03 = 0; symbol_counter_03 < 16; symbol_counter_03++) {
                            if (machine_03_pos - 7 + symbol_counter_03 > -1) {
                                if (tape_03[machine_03_pos - 7 + symbol_counter_03] == 1) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_03, 210, zero, lstrlen(zero));
                                }
                                if (tape_03[machine_03_pos - 7 + symbol_counter_03] == 2) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_03, 210, one, lstrlen(one));
                                }
                                if (tape_03[machine_03_pos - 7 + symbol_counter_03] == 3) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_03, 210, e, lstrlen(e));
                                }
                                if (tape_03[machine_03_pos - 7 + symbol_counter_03] == 4) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_03, 210, x, lstrlen(x));
                                }
                                if (tape_03[machine_03_pos - 7 + symbol_counter_03] == 5) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_03, 210, TEXT("y"), lstrlen(TEXT("y")));
                                }
                            }
                        }
                        UpdateWindow(hWnd);
                        Sleep(500);
                    }
                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                    SelectObject(hdc1, hFont);
                    TextOut(hdc1, 260, 430, TEXT("出力："), lstrlen(TEXT("出力：")));
                    for (int output_counter_03 = 0; output_counter_03 < 21; output_counter_03++) {
                        if (tape_03[output_counter_03] == 0) {
                            TextOut(hdc1, 340 + 20 * output_counter_03, 430, TEXT(" "), lstrlen(TEXT(" ")));
                        }
                        if (tape_03[output_counter_03] == 1) {
                            TextOut(hdc1, 340 + 20 * output_counter_03, 430, TEXT("0"), lstrlen(TEXT("0")));
                        }
                        if (tape_03[output_counter_03] == 2) {
                            TextOut(hdc1, 340 + 20 * output_counter_03, 430, TEXT("1"), lstrlen(TEXT("1")));
                        }
                        if (tape_03[output_counter_03] == 3) {
                            TextOut(hdc1, 340 + 20 * output_counter_03, 430, TEXT("e"), lstrlen(TEXT("e")));
                        }
                        if (tape_03[output_counter_03] == 4) {
                            TextOut(hdc1, 340 + 20 * output_counter_03, 430, TEXT("x"), lstrlen(TEXT("x")));
                        }
                        if (tape_03[output_counter_03] == 5) {
                            TextOut(hdc1, 340 + 20 * output_counter_03, 430, TEXT("y"), lstrlen(TEXT("x")));
                        }
                    }
                    run_checker3 = true;
                }

                if (set_program == 4) {
                    while (machine_04 != 3) {
                        Rectangle(hdc1, 300, 150, 1100, 400);
                        Ellipse(hdc1, 650, 250, 700, 300);
                        if (machine_04 == 0) {
                            if (tape_04[machine_04_pos] == 1) {
                                tape_04[machine_04_pos] = 4;
                                machine_04_pos++;
                                machine_04 = 5;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_c1, lstrlen(config_c1));
                            }
                            else if (tape_04[machine_04_pos] == 2) {
                                machine_04_pos++;
                                machine_04 = 4;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_b1, lstrlen(config_b1));
                            }
                            else if (tape_04[machine_04_pos] == 3) {
                                machine_04 = 3;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_e, lstrlen(config_e));
                            }
                        }
                        else if (machine_04 == 1) {
                            if (tape_04[machine_04_pos] == 0) {
                                tape_04[machine_04_pos] = 1;
                                machine_04_pos = machine_04_pos - 1;
                                machine_04 = 6;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_d1, lstrlen(config_d1));
                            }
                            else {
                                machine_04_pos++;
                                machine_04 = 5;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_c1, lstrlen(config_c1));
                            }
                        }
                        else if (machine_04 == 2) {
                            if (tape_04[machine_04_pos] == 4) {
                                machine_04_pos++;
                                machine_04 = 4;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_b1, lstrlen(config_b1));
                            }
                            else {
                                machine_04_pos = machine_04_pos - 1;
                                machine_04 = 6;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_d1, lstrlen(config_d1));
                            }
                        }
                        else if (machine_04 == 4) {
                            machine_04_pos++;
                            machine_04 = 0;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                        }
                        else if (machine_04 == 5) {
                            machine_04_pos++;
                            machine_04 = 1;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_c, lstrlen(config_c));
                        }
                        else if (machine_04 == 6) {
                            machine_04_pos = machine_04_pos - 1;
                            machine_04 = 2;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_d, lstrlen(config_d));
                        }

                        for (int circle_counter_04 = 0; circle_counter_04 < 16; circle_counter_04++) {
                            Ellipse(hdc1, 300 + 50 * circle_counter_04, 200, 350 + 50 * circle_counter_04, 250);
                        }

                        for (int symbol_counter_04 = 0; symbol_counter_04 < 16; symbol_counter_04++) {
                            if (machine_04_pos - 7 + symbol_counter_04 > -1) {
                                if (tape_04[machine_04_pos - 7 + symbol_counter_04] == 1) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_04, 210, zero, lstrlen(zero));
                                }
                                if (tape_04[machine_04_pos - 7 + symbol_counter_04] == 2) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_04, 210, TEXT("+"), lstrlen(TEXT("+")));
                                }
                                if (tape_04[machine_04_pos - 7 + symbol_counter_04] == 3) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_04, 210, TEXT("="), lstrlen(TEXT("=")));
                                }
                                if (tape_04[machine_04_pos - 7 + symbol_counter_04] == 4) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_04, 210, x, lstrlen(x));
                                }
                            }
                        }
                        UpdateWindow(hWnd);
                        Sleep(500);
                    }

                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                    SelectObject(hdc1, hFont);
                    TextOut(hdc1, 260, 430, TEXT("出力："), lstrlen(TEXT("出力：")));
                    for (int output_counter_04 = 0; output_counter_04 < 32; output_counter_04++) {
                        if (tape_04[output_counter_04] == 0) {
                            TextOut(hdc1, 340 + 20 * output_counter_04, 430, TEXT(" "), lstrlen(TEXT(" ")));
                        }
                        if (tape_04[output_counter_04] == 1) {
                            TextOut(hdc1, 340 + 20 * output_counter_04, 430, TEXT("0"), lstrlen(TEXT("0")));
                        }
                        if (tape_04[output_counter_04] == 2) {
                            TextOut(hdc1, 340 + 20 * output_counter_04, 430, TEXT("+"), lstrlen(TEXT("+")));
                        }
                        if (tape_04[output_counter_04] == 3) {
                            TextOut(hdc1, 340 + 20 * output_counter_04, 430, TEXT("="), lstrlen(TEXT("=")));
                        }
                        if (tape_04[output_counter_04] == 4) {
                            TextOut(hdc1, 340 + 20 * output_counter_04, 430, TEXT("x"), lstrlen(TEXT("x")));
                        }
                        
                    }
                    run_checker4 = true;
                }

                if (set_program == 5) {
                    while (machine_05 != 3) {
                        Rectangle(hdc1, 300, 150, 1100, 400);
                        Ellipse(hdc1, 650, 250, 700, 300);
                        if (machine_05 == 0) {
                            if (tape_05[machine_05_pos] == 1) {
                                tape_05[machine_05_pos] = 4;
                                machine_05_pos++;
                                machine_05 = 5;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_c1, lstrlen(config_c1));
                            }
                            else if (tape_05[machine_05_pos] == 2) {
                                machine_05_pos++;
                                machine_05 = 10;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 664, 258, config_f1, lstrlen(config_f1));
                            }
                        }
                        else if (machine_05 == 1) {
                            if (tape_05[machine_05_pos] == 0) {
                                tape_05[machine_05_pos] = 1;
                                machine_05_pos = machine_05_pos - 1;
                                machine_05 = 6;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_d1, lstrlen(config_d1));
                            }
                            else {
                                machine_05_pos++;
                                machine_05 = 5;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_c1, lstrlen(config_c1));
                            }
                        }
                        else if (machine_05 == 2) {
                            if (tape_05[machine_05_pos] == 4) {
                                machine_05_pos++;
                                machine_05 = 4;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_b1, lstrlen(config_b1));
                            }
                            else {
                                machine_05_pos = machine_05_pos - 1;
                                machine_05 = 6;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_d1, lstrlen(config_d1));
                            }
                        }
                        else if (machine_05 == 4) {
                            machine_05_pos++;
                            machine_05 = 0;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                        }
                        else if (machine_05 == 5) {
                            machine_05_pos++;
                            machine_05 = 1;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_c, lstrlen(config_c));
                        }
                        else if (machine_05 == 6) {
                            machine_05_pos = machine_05_pos - 1;
                            machine_05 = 2;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_d, lstrlen(config_d));
                        }
                        else if (machine_05 == 7) {
                            if (tape_05[machine_05_pos] == 1) {
                                tape_05[machine_05_pos] = 4;
                                machine_05_pos++;
                                machine_05 = 11;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_g1, lstrlen(config_g1));
                            }
                            else if (tape_05[machine_05_pos] == 3) {
                                machine_05 = 3;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_e, lstrlen(config_e));
                            }
                        }
                        else if (machine_05 == 8) {
                            if (tape_05[machine_05_pos] == 0) {
                                machine_05_pos = machine_05_pos - 1;
                                machine_05 = 12;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_h1, lstrlen(config_h1));
                            }
                            else {
                                machine_05_pos++;
                                machine_05 = 11;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_g1, lstrlen(config_g1));
                            }
                        }
                        else if (machine_05 == 9) {
                            if (tape_05[machine_05_pos] == 4) {
                                machine_05_pos++;
                                machine_05 = 10;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 664, 258, config_f1, lstrlen(config_f1));
                            }
                            else {
                                machine_05_pos = machine_05_pos - 1;
                                machine_05 = 13;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_h2, lstrlen(config_h2));
                            }
                        }
                        else if (machine_05 == 10) {
                            machine_05_pos++;
                            machine_05 = 7;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_f, lstrlen(config_f));
                        }
                        else if (machine_05 == 11) {
                            machine_05_pos++;
                            machine_05 = 8;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_g, lstrlen(config_g));
                        }
                        else if (machine_05 == 12) {
                            machine_05_pos = machine_05_pos - 1;
                            tape_05[machine_05_pos] = 0;
                            machine_05 = 9;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_h, lstrlen(config_h));
                        }
                        else if (machine_05 == 13) {
                            machine_05_pos = machine_05_pos - 1;
                            machine_05 = 9;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_h, lstrlen(config_h));
                        }

                        for (int circle_counter_05 = 0; circle_counter_05 < 16; circle_counter_05++) {
                            Ellipse(hdc1, 300 + 50 * circle_counter_05, 200, 350 + 50 * circle_counter_05, 250);
                        }

                        for (int symbol_counter_05 = 0; symbol_counter_05 < 16; symbol_counter_05++) {
                            if (machine_05_pos - 7 + symbol_counter_05 > -1) {
                                if (tape_05[machine_05_pos - 7 + symbol_counter_05] == 1) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_05, 210, zero, lstrlen(zero));
                                }
                                if (tape_05[machine_05_pos - 7 + symbol_counter_05] == 2) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_05, 210, TEXT("-"), lstrlen(TEXT("-")));
                                }
                                if (tape_05[machine_05_pos - 7 + symbol_counter_05] == 3) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_05, 210, TEXT("="), lstrlen(TEXT("=")));
                                }
                                if (tape_05[machine_05_pos - 7 + symbol_counter_05] == 4) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_05, 210, x, lstrlen(x));
                                }
                            }
                        }
                        UpdateWindow(hWnd);
                        Sleep(500);
                    }

                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                    SelectObject(hdc1, hFont);
                    TextOut(hdc1, 260, 430, TEXT("出力："), lstrlen(TEXT("出力：")));
                    for (int output_counter_05 = 0; output_counter_05 < 32; output_counter_05++) {
                        if (tape_05[output_counter_05] == 0) {
                            TextOut(hdc1, 340 + 20 * output_counter_05, 430, TEXT(" "), lstrlen(TEXT(" ")));
                        }
                        if (tape_05[output_counter_05] == 1) {
                            TextOut(hdc1, 340 + 20 * output_counter_05, 430, TEXT("0"), lstrlen(TEXT("0")));
                        }
                        if (tape_05[output_counter_05] == 2) {
                            TextOut(hdc1, 340 + 20 * output_counter_05, 430, TEXT("-"), lstrlen(TEXT("-")));
                        }
                        if (tape_05[output_counter_05] == 3) {
                            TextOut(hdc1, 340 + 20 * output_counter_05, 430, TEXT("="), lstrlen(TEXT("=")));
                        }
                        if (tape_05[output_counter_05] == 4) {
                            TextOut(hdc1, 340 + 20 * output_counter_05, 430, TEXT("x"), lstrlen(TEXT("x")));
                        }

                    }
                    run_checker5 = true;
                }

                if (set_program == 6) {
                    set_number = SendMessageW(combobox6, CB_GETCURSEL, 0, 0);
                    if (set_number > -1) {
                        for (int initial_condition_counter_06 = 0; initial_condition_counter_06 < 2*(set_number + 1); initial_condition_counter_06 = initial_condition_counter_06 + 2) {
                            tape_06[initial_condition_counter_06] = 1;
                        }
                        tape_06[2*(set_number + 1)] = 3;

                        while (machine_06 != 20) {
                            Rectangle(hdc1, 300, 150, 1100, 400);
                            Ellipse(hdc1, 650, 250, 700, 300);
                            if (machine_06 == 0) {
                                if (tape_06[machine_06_pos] == 1) {
                                    tape_06[machine_06_pos] = 4;
                                    machine_06_pos++;
                                    machine_06 = 3;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_c1, lstrlen(config_c1));
                                }
                                else if (tape_06[machine_06_pos] == 3) {
                                    machine_06_pos++;
                                    machine_06 = 9;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 664, 258, config_f1, lstrlen(config_f1));
                                }
                            }
                            else if (machine_06 == 1) {
                                    machine_06_pos++;
                                    machine_06 = 0;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                            }
                            else if (machine_06 == 2) {
                                if (tape_06[machine_06_pos] == 1) {
                                    machine_06_pos++;
                                    machine_06 = 3;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_c1, lstrlen(config_c1));
                                }
                                else if (tape_06[machine_06_pos] == 3) {
                                    machine_06_pos++;
                                    machine_06 = 5;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_d1, lstrlen(config_d1));
                                }
                            }
                            else if (machine_06 == 3) {
                                machine_06_pos++;
                                machine_06 = 2;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_c, lstrlen(config_c));
                            }
                            else if (machine_06 == 4) {
                                if (tape_06[machine_06_pos] == 0) {
                                    tape_06[machine_06_pos] = 2;
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 7;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_e1, lstrlen(config_e1));
                                }
                                else if (tape_06[machine_06_pos] == 1) {
                                    tape_06[machine_06_pos] = 2;
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 7;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_e1, lstrlen(config_e1));
                                }
                                else if (tape_06[machine_06_pos] == 2) {
                                    tape_06[machine_06_pos] = 1;
                                    machine_06_pos++;
                                    machine_06 = 5;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_d1, lstrlen(config_d1));
                                }
                            }
                            else if (machine_06 == 5) {
                                machine_06_pos++;
                                machine_06 = 4;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_d, lstrlen(config_d));
                            }
                            else if (machine_06 == 6) {
                                if (tape_06[machine_06_pos] == 4) {
                                    machine_06_pos++;
                                    machine_06 = 1;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_b1, lstrlen(config_b1));
                                }
                                else {
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 7;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_e1, lstrlen(config_e1));
                                }
                            }
                            else if (machine_06 == 7) {
                                machine_06_pos = machine_06_pos - 1;
                                machine_06 = 6;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_e, lstrlen(config_e));
                            }
                            else if (machine_06 == 8) {
                                if (tape_06[machine_06_pos] == 0) {
                                    tape_06[machine_06_pos] = 3;
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 11;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_g1, lstrlen(config_g1));
                                }
                                else {
                                    machine_06_pos++;
                                    machine_06 = 9;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 664, 258, config_f1, lstrlen(config_f1));
                                }
                            }
                            else if (machine_06 == 9) {
                                machine_06_pos++;
                                machine_06 = 8;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_f, lstrlen(config_f));
                            }
                            else if (machine_06 == 10) {
                                if (tape_06[machine_06_pos] == 1) {
                                    tape_06[machine_06_pos] = 5;
                                    machine_06_pos++;
                                    machine_06 = 13;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_h1, lstrlen(config_h1));
                                }
                                else if (tape_06[machine_06_pos] == 2) {
                                    tape_06[machine_06_pos] = 5;
                                    machine_06_pos++;
                                    machine_06 = 15;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 665, 258, config_i1, lstrlen(config_i1));
                                }
                                else if (tape_06[machine_06_pos] == 3) {
                                    machine_06 = 20;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 668, 258, config_p, lstrlen(config_p));
                                }
                                else {
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 11;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_g1, lstrlen(config_g1));
                                }
                            }
                            else if (machine_06 == 11) {
                                machine_06_pos = machine_06_pos - 1;
                                machine_06 = 10;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_g, lstrlen(config_g));
                            }
                            else if (machine_06 == 12) {
                                if (tape_06[machine_06_pos] == 0) {
                                    tape_06[machine_06_pos] = 1;
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 17;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 665, 258, config_j1, lstrlen(config_j1));
                                }
                                else {
                                    machine_06_pos++;
                                    machine_06 = 13;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_h1, lstrlen(config_h1));
                                }
                            }
                            else if (machine_06 == 13) {
                                machine_06_pos++;
                                machine_06 = 12;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_h, lstrlen(config_h));
                            }
                            else if (machine_06 == 14) {
                                if (tape_06[machine_06_pos] == 0) {
                                    tape_06[machine_06_pos] = 2;
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 17;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 665, 258, config_j1, lstrlen(config_j1));
                                }
                                else {
                                    machine_06_pos++;
                                    machine_06 = 15;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 665, 258, config_i1, lstrlen(config_i1));
                                }
                            }
                            else if (machine_06 == 15) {
                                machine_06_pos++;
                                machine_06 = 14;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 672, 258, config_i, lstrlen(config_i));
                            }
                            else if (machine_06 == 16) {
                                if (tape_06[machine_06_pos] == 5) {
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 19;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_k1, lstrlen(config_k1));
                                }
                                else {
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 17;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 665, 258, config_j1, lstrlen(config_j1));
                                }
                            }
                            else if (machine_06 == 17) {
                                machine_06_pos = machine_06_pos - 1;
                                machine_06 = 16;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 672, 258, config_j, lstrlen(config_j));
                            }
                            else if (machine_06 == 18) {
                                if (tape_06[machine_06_pos] == 5) {
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 19;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_k1, lstrlen(config_k1));
                                }
                                else {
                                    machine_06 = 10;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 668, 258, config_g, lstrlen(config_g));
                                }
                            }
                            else if (machine_06 == 19) {
                                machine_06_pos = machine_06_pos - 1;
                                machine_06 = 18;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_k, lstrlen(config_k));
                            }

                            for (int circle_counter_06 = 0; circle_counter_06 < 16; circle_counter_06++) {
                                Ellipse(hdc1, 300 + 50 * circle_counter_06, 200, 350 + 50 * circle_counter_06, 250);
                            }

                            for (int symbol_counter_06 = 0; symbol_counter_06 < 16; symbol_counter_06++) {
                                if (machine_06_pos - 7 + symbol_counter_06 > -1) {
                                    if (tape_06[machine_06_pos - 7 + symbol_counter_06] == 1) {
                                        hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                        SelectObject(hdc1, hFont);
                                        TextOut(hdc1, 317 + 50 * symbol_counter_06, 210, zero, lstrlen(zero));
                                    }
                                    if (tape_06[machine_06_pos - 7 + symbol_counter_06] == 2) {
                                        hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                        SelectObject(hdc1, hFont);
                                        TextOut(hdc1, 317 + 50 * symbol_counter_06, 210, one, lstrlen(one));
                                    }
                                    if (tape_06[machine_06_pos - 7 + symbol_counter_06] == 3) {
                                        hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                        SelectObject(hdc1, hFont);
                                        TextOut(hdc1, 317 + 50 * symbol_counter_06, 210, TEXT("="), lstrlen(TEXT("=")));
                                    }
                                    if (tape_06[machine_06_pos - 7 + symbol_counter_06] == 4) {
                                        hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                        SelectObject(hdc1, hFont);
                                        TextOut(hdc1, 317 + 50 * symbol_counter_06, 210, x, lstrlen(x));
                                    }
                                    if (tape_06[machine_06_pos - 7 + symbol_counter_06] == 5) {
                                        hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                        SelectObject(hdc1, hFont);
                                        TextOut(hdc1, 317 + 50 * symbol_counter_06, 210, TEXT("y"), lstrlen(TEXT("y")));
                                    }
                                }
                            }
                            UpdateWindow(hWnd);
                            Sleep(500);
                        }

                        hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                        SelectObject(hdc1, hFont);
                        TextOut(hdc1, 260, 430, TEXT("出力："), lstrlen(TEXT("出力：")));
                        for (int output_counter_06 = 0; output_counter_06 < 34; output_counter_06++) {
                            if (tape_06[output_counter_06] == 0) {
                                TextOut(hdc1, 340 + 20 * output_counter_06, 430, TEXT(" "), lstrlen(TEXT(" ")));
                            }
                            if (tape_06[output_counter_06] == 1) {
                                TextOut(hdc1, 340 + 20 * output_counter_06, 430, TEXT("0"), lstrlen(TEXT("0")));
                            }
                            if (tape_06[output_counter_06] == 2) {
                                TextOut(hdc1, 340 + 20 * output_counter_06, 430, TEXT("1"), lstrlen(TEXT("1")));
                            }
                            if (tape_06[output_counter_06] == 3) {
                                TextOut(hdc1, 340 + 20 * output_counter_06, 430, TEXT("="), lstrlen(TEXT("=")));
                            }
                            if (tape_06[output_counter_06] == 4) {
                                TextOut(hdc1, 340 + 20 * output_counter_06, 430, TEXT("x"), lstrlen(TEXT("x")));
                            }
                            if (tape_06[output_counter_06] == 5) {
                                TextOut(hdc1, 340 + 20 * output_counter_06, 430, TEXT("y"), lstrlen(TEXT("y")));
                            }
                        }
                        run_checker6 = true;
                    }
                    
                }
                break;
            case 2:
                if (set_program == 1) {
                    if (step_counter_01 < 20) {
                        Rectangle(hdc1, 300, 150, 1100, 400);
                        Ellipse(hdc1, 650, 250, 700, 300);
                        if (machine_01 == 0) {
                            machine_01 = 1;
                            tape_01[machine_01_pos] = 1;
                            machine_01_pos++;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_c, lstrlen(config_c));
                        }
                        else if (machine_01 == 1) {
                            machine_01 = 2;
                            machine_01_pos++;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_e, lstrlen(config_e));
                        }
                        else if (machine_01 == 2) {
                            machine_01 = 3;
                            tape_01[machine_01_pos] = 2;
                            machine_01_pos++;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_f, lstrlen(config_f));
                        }
                        else {
                            machine_01 = 0;
                            machine_01_pos++;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                        }

                        for (int circle_counter_01 = 0; circle_counter_01 < 16; circle_counter_01++) {
                            Ellipse(hdc1, 300 + 50 * circle_counter_01, 200, 350 + 50 * circle_counter_01, 250);
                        }

                        for (int symbol_counter_01 = 0; symbol_counter_01 < 7; symbol_counter_01++) {
                            if (machine_01_pos - 1 - symbol_counter_01 > -1) {
                                if (tape_01[machine_01_pos - 1 - symbol_counter_01] == 1) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 617 - 50 * symbol_counter_01, 210, zero, lstrlen(zero));
                                }
                                if (tape_01[machine_01_pos - 1 - symbol_counter_01] == 2) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 617 - 50 * symbol_counter_01, 210, one, lstrlen(one));
                                }
                            }

                        }
                        step_counter_01++;
                        run_checker1 = true;
                    }
                }
                if (set_program == 2) {
                    if (machine_02_pos < 45) {
                        Rectangle(hdc1, 300, 150, 1100, 400);
                        Ellipse(hdc1, 650, 250, 700, 300);
                        if (machine_02 == 0) {
                            tape_02[machine_02_pos] = 3;
                            machine_02_pos++;
                            machine_02 = 1;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 660, 258, config_o1, lstrlen(config_o1));
                        }
                        else if (machine_02 == 1) {
                            tape_02[machine_02_pos] = 3;
                            machine_02_pos++;
                            machine_02 = 2;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 660, 258, config_o2, lstrlen(config_o2));
                        }
                        else if (machine_02 == 2) {
                            tape_02[machine_02_pos] = 1;
                            machine_02_pos++;
                            machine_02 = 3;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 660, 258, config_o3, lstrlen(config_o3));
                        }
                        else if (machine_02 == 3) {
                            machine_02_pos++;
                            machine_02 = 4;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 660, 258, config_o4, lstrlen(config_o4));
                        }
                        else if (machine_02 == 4) {
                            tape_02[machine_02_pos] = 1;
                            machine_02_pos = machine_02_pos - 1;
                            machine_02 = 5;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 660, 258, config_o5, lstrlen(config_o5));
                        }
                        else if (machine_02 == 5) {
                            machine_02_pos = machine_02_pos - 1;
                            machine_02 = 6;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_o, lstrlen(config_o));
                        }
                        else if (machine_02 == 6) {
                            if (tape_02[machine_02_pos] == 1) {
                                machine_02 = 10;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_q, lstrlen(config_q));
                            }
                            if (tape_02[machine_02_pos] == 2) {
                                machine_02_pos++;
                                machine_02 = 7;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_o6, lstrlen(config_o6));
                            }
                        }
                        else if (machine_02 == 7) {
                            tape_02[machine_02_pos] = 4;
                            machine_02_pos = machine_02_pos - 1;
                            machine_02 = 8;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 660, 258, config_o7, lstrlen(config_o7));
                        }
                        else if (machine_02 == 8) {
                            machine_02_pos = machine_02_pos - 1;
                            machine_02 = 9;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 660, 258, config_o8, lstrlen(config_o8));
                        }
                        else if (machine_02 == 9) {
                            machine_02_pos = machine_02_pos - 1;
                            machine_02 = 6;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_o, lstrlen(config_o));
                        }
                        else if (machine_02 == 10) {
                            if (tape_02[machine_02_pos] == 1) {
                                machine_02_pos++;
                                machine_02 = 11;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_q1, lstrlen(config_q1));
                            }
                            else if (tape_02[machine_02_pos] == 2) {
                                machine_02_pos++;
                                machine_02 = 11;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_q1, lstrlen(config_q1));
                            }
                            else {
                                tape_02[machine_02_pos] = 2;
                                machine_02_pos = machine_02_pos - 1;
                                machine_02 = 12;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_p, lstrlen(config_p));
                            }
                        }
                        else if (machine_02 == 11) {
                            machine_02_pos++;
                            machine_02 = 10;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_q, lstrlen(config_q));
                        }
                        else if (machine_02 == 12) {
                            if (tape_02[machine_02_pos] == 4) {
                                tape_02[machine_02_pos] = 0;
                                machine_02_pos++;
                                machine_02 = 10;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_q, lstrlen(config_q));
                            }
                            else if (tape_02[machine_02_pos] == 3) {
                                machine_02_pos++;
                                machine_02 = 14;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_f, lstrlen(config_f));
                            }
                            else if (tape_02[machine_02_pos] == 0) {
                                machine_02_pos = machine_02_pos - 1;
                                machine_02 = 13;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_p1, lstrlen(config_p1));
                            }
                        }
                        else if (machine_02 == 13) {
                            machine_02_pos = machine_02_pos - 1;
                            machine_02 = 12;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_p, lstrlen(config_p));
                        }
                        else if (machine_02 == 14) {
                            if (tape_02[machine_02_pos] == 1) {
                                machine_02_pos++;
                                machine_02 = 15;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 664, 258, config_f1, lstrlen(config_f1));
                            }
                            else if (tape_02[machine_02_pos] == 2) {
                                machine_02_pos++;
                                machine_02 = 15;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 664, 258, config_f1, lstrlen(config_f1));
                            }
                            else if (tape_02[machine_02_pos] == 0) {
                                tape_02[machine_02_pos] = 1;
                                machine_02_pos = machine_02_pos - 1;
                                machine_02 = 16;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_o9, lstrlen(config_o9));
                            }
                        }
                        else if (machine_02 == 15) {
                            machine_02_pos++;
                            machine_02 = 14;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_f, lstrlen(config_f));
                        }
                        else if (machine_02 == 16) {
                            machine_02_pos = machine_02_pos - 1;
                            machine_02 = 6;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_o, lstrlen(config_o));
                        }

                        for (int circle_counter_02 = 0; circle_counter_02 < 16; circle_counter_02++) {
                            Ellipse(hdc1, 300 + 50 * circle_counter_02, 200, 350 + 50 * circle_counter_02, 250);
                        }

                        for (int symbol_counter_02 = 0; symbol_counter_02 < 16; symbol_counter_02++) {
                            if (machine_02_pos - 7 + symbol_counter_02 > -1) {
                                if (tape_02[machine_02_pos - 7 + symbol_counter_02] == 1) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_02, 210, zero, lstrlen(zero));
                                }
                                if (tape_02[machine_02_pos - 7 + symbol_counter_02] == 2) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_02, 210, one, lstrlen(one));
                                }
                                if (tape_02[machine_02_pos - 7 + symbol_counter_02] == 3) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_02, 210, e, lstrlen(e));
                                }
                                if (tape_02[machine_02_pos - 7 + symbol_counter_02] == 4) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_02, 210, x, lstrlen(x));
                                }
                            }

                        }
                        run_checker2 = true;
                    }
                }

                if (set_program == 3) {
                    if (machine_03 != 4) {
                        Rectangle(hdc1, 300, 150, 1100, 400);
                        Ellipse(hdc1, 650, 250, 700, 300);
                        if (machine_03 == 0) {
                            if (tape_03[machine_03_pos] == 3) {
                                machine_03_pos = machine_03_pos - 1;
                                machine_03 = 1;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_e, lstrlen(config_e));
                            }
                            else {
                                machine_03_pos = machine_03_pos - 1;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_d, lstrlen(config_d));
                            }
                        }
                        else if (machine_03 == 1) {
                            if (tape_03[machine_03_pos] == 4) {
                                machine_03 = 3;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_c, lstrlen(config_c));
                            }
                            else if (tape_03[machine_03_pos] == 0) {
                                machine_03_pos++;
                                machine_03 = 2;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_f, lstrlen(config_f));
                            }
                            else {
                                machine_03_pos++;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_e, lstrlen(config_e));
                            }
                        }
                        else if (machine_03 == 2) {
                            if (tape_03[machine_03_pos] == 4) {
                                machine_03 = 3;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_c, lstrlen(config_c));
                            }
                            else if (tape_03[machine_03_pos] == 0) {
                                machine_03_pos++;
                                machine_03 = 4;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                            }
                            else {
                                machine_03_pos++;
                                machine_03 = 1;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_e, lstrlen(config_e));
                            }
                        }
                        else if (machine_03 == 3) {
                            tape_03[machine_03_pos] = 5;
                            machine_03 = 0;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_d, lstrlen(config_d));
                        }

                        for (int circle_counter_03 = 0; circle_counter_03 < 16; circle_counter_03++) {
                            Ellipse(hdc1, 300 + 50 * circle_counter_03, 200, 350 + 50 * circle_counter_03, 250);
                        }

                        for (int symbol_counter_03 = 0; symbol_counter_03 < 16; symbol_counter_03++) {
                            if (machine_03_pos - 7 + symbol_counter_03 > -1) {
                                if (tape_03[machine_03_pos - 7 + symbol_counter_03] == 1) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_03, 210, zero, lstrlen(zero));
                                }
                                if (tape_03[machine_03_pos - 7 + symbol_counter_03] == 2) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_03, 210, one, lstrlen(one));
                                }
                                if (tape_03[machine_03_pos - 7 + symbol_counter_03] == 3) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_03, 210, e, lstrlen(e));
                                }
                                if (tape_03[machine_03_pos - 7 + symbol_counter_03] == 4) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_03, 210, x, lstrlen(x));
                                }
                                if (tape_03[machine_03_pos - 7 + symbol_counter_03] == 5) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_03, 210, TEXT("y"), lstrlen(TEXT("y")));
                                }
                            }
                        }
                        run_checker3 = true;
                    }
                }

                if (set_program == 4) {
                    if (machine_04 != 3) {
                        Rectangle(hdc1, 300, 150, 1100, 400);
                        Ellipse(hdc1, 650, 250, 700, 300);
                        if (machine_04 == 0) {
                            if (tape_04[machine_04_pos] == 1) {
                                tape_04[machine_04_pos] = 4;
                                machine_04_pos++;
                                machine_04 = 5;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_c1, lstrlen(config_c1));
                            }
                            else if (tape_04[machine_04_pos] == 2) {
                                machine_04_pos++;
                                machine_04 = 4;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_b1, lstrlen(config_b1));
                            }
                            else if (tape_04[machine_04_pos] == 3) {
                                machine_04 = 3;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_e, lstrlen(config_e));
                            }
                        }
                        else if (machine_04 == 1) {
                            if (tape_04[machine_04_pos] == 0) {
                                tape_04[machine_04_pos] = 1;
                                machine_04_pos = machine_04_pos - 1;
                                machine_04 = 6;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_d1, lstrlen(config_d1));
                            }
                            else {
                                machine_04_pos++;
                                machine_04 = 5;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_c1, lstrlen(config_c1));
                            }
                        }
                        else if (machine_04 == 2) {
                            if (tape_04[machine_04_pos] == 4) {
                                machine_04_pos++;
                                machine_04 = 4;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_b1, lstrlen(config_b1));
                            }
                            else {
                                machine_04_pos = machine_04_pos - 1;
                                machine_04 = 6;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_d1, lstrlen(config_d1));
                            }
                        }
                        else if (machine_04 == 4) {
                            machine_04_pos++;
                            machine_04 = 0;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                        }
                        else if (machine_04 == 5) {
                            machine_04_pos++;
                            machine_04 = 1;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_c, lstrlen(config_c));
                        }
                        else if (machine_04 == 6) {
                            machine_04_pos = machine_04_pos - 1;
                            machine_04 = 2;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_d, lstrlen(config_d));
                        }

                        for (int circle_counter_04 = 0; circle_counter_04 < 16; circle_counter_04++) {
                            Ellipse(hdc1, 300 + 50 * circle_counter_04, 200, 350 + 50 * circle_counter_04, 250);
                        }

                        for (int symbol_counter_04 = 0; symbol_counter_04 < 16; symbol_counter_04++) {
                            if (machine_04_pos - 7 + symbol_counter_04 > -1) {
                                if (tape_04[machine_04_pos - 7 + symbol_counter_04] == 1) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_04, 210, zero, lstrlen(zero));
                                }
                                if (tape_04[machine_04_pos - 7 + symbol_counter_04] == 2) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_04, 210, TEXT("+"), lstrlen(TEXT("+")));
                                }
                                if (tape_04[machine_04_pos - 7 + symbol_counter_04] == 3) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_04, 210, TEXT("="), lstrlen(TEXT("=")));
                                }
                                if (tape_04[machine_04_pos - 7 + symbol_counter_04] == 4) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_04, 210, x, lstrlen(x));
                                }
                            }
                        }
                        run_checker4 = true;
                    }
                }

                if (set_program == 5) {
                    if (machine_05 != 3) {
                        Rectangle(hdc1, 300, 150, 1100, 400);
                        Ellipse(hdc1, 650, 250, 700, 300);
                        if (machine_05 == 0) {
                            if (tape_05[machine_05_pos] == 1) {
                                tape_05[machine_05_pos] = 4;
                                machine_05_pos++;
                                machine_05 = 5;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_c1, lstrlen(config_c1));
                            }
                            else if (tape_05[machine_05_pos] == 2) {
                                machine_05_pos++;
                                machine_05 = 10;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 664, 258, config_f1, lstrlen(config_f1));
                            }
                        }
                        else if (machine_05 == 1) {
                            if (tape_05[machine_05_pos] == 0) {
                                tape_05[machine_05_pos] = 1;
                                machine_05_pos = machine_05_pos - 1;
                                machine_05 = 6;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_d1, lstrlen(config_d1));
                            }
                            else {
                                machine_05_pos++;
                                machine_05 = 5;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_c1, lstrlen(config_c1));
                            }
                        }
                        else if (machine_05 == 2) {
                            if (tape_05[machine_05_pos] == 4) {
                                machine_05_pos++;
                                machine_05 = 4;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_b1, lstrlen(config_b1));
                            }
                            else {
                                machine_05_pos = machine_05_pos - 1;
                                machine_05 = 6;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_d1, lstrlen(config_d1));
                            }
                        }
                        else if (machine_05 == 4) {
                            machine_05_pos++;
                            machine_05 = 0;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                        }
                        else if (machine_05 == 5) {
                            machine_05_pos++;
                            machine_05 = 1;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_c, lstrlen(config_c));
                        }
                        else if (machine_05 == 6) {
                            machine_05_pos = machine_05_pos - 1;
                            machine_05 = 2;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_d, lstrlen(config_d));
                        }
                        else if (machine_05 == 7) {
                            if (tape_05[machine_05_pos] == 1) {
                                tape_05[machine_05_pos] = 4;
                                machine_05_pos++;
                                machine_05 = 11;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_g1, lstrlen(config_g1));
                            }
                            else if (tape_05[machine_05_pos] == 3) {
                                machine_05 = 3;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_e, lstrlen(config_e));
                            }
                        }
                        else if (machine_05 == 8) {
                            if (tape_05[machine_05_pos] == 0) {
                                machine_05_pos = machine_05_pos - 1;
                                machine_05 = 12;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_h1, lstrlen(config_h1));
                            }
                            else {
                                machine_05_pos++;
                                machine_05 = 11;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_g1, lstrlen(config_g1));
                            }
                        }
                        else if (machine_05 == 9) {
                            if (tape_05[machine_05_pos] == 4) {
                                machine_05_pos++;
                                machine_05 = 10;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 664, 258, config_f1, lstrlen(config_f1));
                            }
                            else {
                                machine_05_pos = machine_05_pos - 1;
                                machine_05 = 13;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 660, 258, config_h2, lstrlen(config_h2));
                            }
                        }
                        else if (machine_05 == 10) {
                            machine_05_pos++;
                            machine_05 = 7;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_f, lstrlen(config_f));
                        }
                        else if (machine_05 == 11) {
                            machine_05_pos++;
                            machine_05 = 8;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_g, lstrlen(config_g));
                        }
                        else if (machine_05 == 12) {
                            machine_05_pos = machine_05_pos - 1;
                            tape_05[machine_05_pos] = 0;
                            machine_05 = 9;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_h, lstrlen(config_h));
                        }
                        else if (machine_05 == 13) {
                            machine_05_pos = machine_05_pos - 1;
                            machine_05 = 9;
                            hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                            SelectObject(hdc1, hFont);
                            TextOut(hdc1, 668, 258, config_h, lstrlen(config_h));
                        }

                        for (int circle_counter_05 = 0; circle_counter_05 < 16; circle_counter_05++) {
                            Ellipse(hdc1, 300 + 50 * circle_counter_05, 200, 350 + 50 * circle_counter_05, 250);
                        }

                        for (int symbol_counter_05 = 0; symbol_counter_05 < 16; symbol_counter_05++) {
                            if (machine_05_pos - 7 + symbol_counter_05 > -1) {
                                if (tape_05[machine_05_pos - 7 + symbol_counter_05] == 1) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_05, 210, zero, lstrlen(zero));
                                }
                                if (tape_05[machine_05_pos - 7 + symbol_counter_05] == 2) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_05, 210, TEXT("-"), lstrlen(TEXT("-")));
                                }
                                if (tape_05[machine_05_pos - 7 + symbol_counter_05] == 3) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_05, 210, TEXT("="), lstrlen(TEXT("=")));
                                }
                                if (tape_05[machine_05_pos - 7 + symbol_counter_05] == 4) {
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 317 + 50 * symbol_counter_05, 210, x, lstrlen(x));
                                }
                            }
                        }
                        run_checker5 = true;
                    }
                }

                if (set_program == 6) {

                    if (run_checker6 == false) {
                        set_number = SendMessageW(combobox6, CB_GETCURSEL, 0, 0);
                    }

                    if (set_number > -1) {

                        if (run_checker6 == false) {
                            for (int initial_condition_counter_06 = 0; initial_condition_counter_06 < 2 * (set_number + 1); initial_condition_counter_06 = initial_condition_counter_06 + 2) {
                                tape_06[initial_condition_counter_06] = 1;
                            }
                            tape_06[2 * (set_number + 1)] = 3;
                        }
                        

                        if (machine_06 != 20) {
                            Rectangle(hdc1, 300, 150, 1100, 400);
                            Ellipse(hdc1, 650, 250, 700, 300);
                            if (machine_06 == 0) {
                                if (tape_06[machine_06_pos] == 1) {
                                    tape_06[machine_06_pos] = 4;
                                    machine_06_pos++;
                                    machine_06 = 3;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_c1, lstrlen(config_c1));
                                }
                                else if (tape_06[machine_06_pos] == 3) {
                                    machine_06_pos++;
                                    machine_06 = 9;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 664, 258, config_f1, lstrlen(config_f1));
                                }
                            }
                            else if (machine_06 == 1) {
                                machine_06_pos++;
                                machine_06 = 0;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_b, lstrlen(config_b));
                            }
                            else if (machine_06 == 2) {
                                if (tape_06[machine_06_pos] == 1) {
                                    machine_06_pos++;
                                    machine_06 = 3;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_c1, lstrlen(config_c1));
                                }
                                else if (tape_06[machine_06_pos] == 3) {
                                    machine_06_pos++;
                                    machine_06 = 5;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_d1, lstrlen(config_d1));
                                }
                            }
                            else if (machine_06 == 3) {
                                machine_06_pos++;
                                machine_06 = 2;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_c, lstrlen(config_c));
                            }
                            else if (machine_06 == 4) {
                                if (tape_06[machine_06_pos] == 0) {
                                    tape_06[machine_06_pos] = 2;
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 7;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_e1, lstrlen(config_e1));
                                }
                                else if (tape_06[machine_06_pos] == 1) {
                                    tape_06[machine_06_pos] = 2;
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 7;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_e1, lstrlen(config_e1));
                                }
                                else if (tape_06[machine_06_pos] == 2) {
                                    tape_06[machine_06_pos] = 1;
                                    machine_06_pos++;
                                    machine_06 = 5;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_d1, lstrlen(config_d1));
                                }
                            }
                            else if (machine_06 == 5) {
                                machine_06_pos++;
                                machine_06 = 4;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_d, lstrlen(config_d));
                            }
                            else if (machine_06 == 6) {
                                if (tape_06[machine_06_pos] == 4) {
                                    machine_06_pos++;
                                    machine_06 = 1;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_b1, lstrlen(config_b1));
                                }
                                else {
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 7;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_e1, lstrlen(config_e1));
                                }
                            }
                            else if (machine_06 == 7) {
                                machine_06_pos = machine_06_pos - 1;
                                machine_06 = 6;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_e, lstrlen(config_e));
                            }
                            else if (machine_06 == 8) {
                                if (tape_06[machine_06_pos] == 0) {
                                    tape_06[machine_06_pos] = 3;
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 11;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_g1, lstrlen(config_g1));
                                }
                                else {
                                    machine_06_pos++;
                                    machine_06 = 9;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 664, 258, config_f1, lstrlen(config_f1));
                                }
                            }
                            else if (machine_06 == 9) {
                                machine_06_pos++;
                                machine_06 = 8;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_f, lstrlen(config_f));
                            }
                            else if (machine_06 == 10) {
                                if (tape_06[machine_06_pos] == 1) {
                                    tape_06[machine_06_pos] = 5;
                                    machine_06_pos++;
                                    machine_06 = 13;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_h1, lstrlen(config_h1));
                                }
                                else if (tape_06[machine_06_pos] == 2) {
                                    tape_06[machine_06_pos] = 5;
                                    machine_06_pos++;
                                    machine_06 = 15;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 665, 258, config_i1, lstrlen(config_i1));
                                }
                                else if (tape_06[machine_06_pos] == 3) {
                                    machine_06 = 20;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 668, 258, config_p, lstrlen(config_p));
                                }
                                else {
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 11;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_g1, lstrlen(config_g1));
                                }
                            }
                            else if (machine_06 == 11) {
                                machine_06_pos = machine_06_pos - 1;
                                machine_06 = 10;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_g, lstrlen(config_g));
                            }
                            else if (machine_06 == 12) {
                                if (tape_06[machine_06_pos] == 0) {
                                    tape_06[machine_06_pos] = 1;
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 17;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 665, 258, config_j1, lstrlen(config_j1));
                                }
                                else {
                                    machine_06_pos++;
                                    machine_06 = 13;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_h1, lstrlen(config_h1));
                                }
                            }
                            else if (machine_06 == 13) {
                                machine_06_pos++;
                                machine_06 = 12;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_h, lstrlen(config_h));
                            }
                            else if (machine_06 == 14) {
                                if (tape_06[machine_06_pos] == 0) {
                                    tape_06[machine_06_pos] = 2;
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 17;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 665, 258, config_j1, lstrlen(config_j1));
                                }
                                else {
                                    machine_06_pos++;
                                    machine_06 = 15;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 665, 258, config_i1, lstrlen(config_i1));
                                }
                            }
                            else if (machine_06 == 15) {
                                machine_06_pos++;
                                machine_06 = 14;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 672, 258, config_i, lstrlen(config_i));
                            }
                            else if (machine_06 == 16) {
                                if (tape_06[machine_06_pos] == 5) {
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 19;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_k1, lstrlen(config_k1));
                                }
                                else {
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 17;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 665, 258, config_j1, lstrlen(config_j1));
                                }
                            }
                            else if (machine_06 == 17) {
                                machine_06_pos = machine_06_pos - 1;
                                machine_06 = 16;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 672, 258, config_j, lstrlen(config_j));
                            }
                            else if (machine_06 == 18) {
                                if (tape_06[machine_06_pos] == 5) {
                                    machine_06_pos = machine_06_pos - 1;
                                    machine_06 = 19;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 660, 258, config_k1, lstrlen(config_k1));
                                }
                                else {
                                    machine_06 = 10;
                                    hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                    SelectObject(hdc1, hFont);
                                    TextOut(hdc1, 668, 258, config_g, lstrlen(config_g));
                                }
                            }
                            else if (machine_06 == 19) {
                                machine_06_pos = machine_06_pos - 1;
                                machine_06 = 18;
                                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                SelectObject(hdc1, hFont);
                                TextOut(hdc1, 668, 258, config_k, lstrlen(config_k));
                            }

                            for (int circle_counter_06 = 0; circle_counter_06 < 16; circle_counter_06++) {
                                Ellipse(hdc1, 300 + 50 * circle_counter_06, 200, 350 + 50 * circle_counter_06, 250);
                            }

                            for (int symbol_counter_06 = 0; symbol_counter_06 < 16; symbol_counter_06++) {
                                if (machine_06_pos - 7 + symbol_counter_06 > -1) {
                                    if (tape_06[machine_06_pos - 7 + symbol_counter_06] == 1) {
                                        hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                        SelectObject(hdc1, hFont);
                                        TextOut(hdc1, 317 + 50 * symbol_counter_06, 210, zero, lstrlen(zero));
                                    }
                                    if (tape_06[machine_06_pos - 7 + symbol_counter_06] == 2) {
                                        hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                        SelectObject(hdc1, hFont);
                                        TextOut(hdc1, 317 + 50 * symbol_counter_06, 210, one, lstrlen(one));
                                    }
                                    if (tape_06[machine_06_pos - 7 + symbol_counter_06] == 3) {
                                        hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                        SelectObject(hdc1, hFont);
                                        TextOut(hdc1, 317 + 50 * symbol_counter_06, 210, TEXT("="), lstrlen(TEXT("=")));
                                    }
                                    if (tape_06[machine_06_pos - 7 + symbol_counter_06] == 4) {
                                        hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                        SelectObject(hdc1, hFont);
                                        TextOut(hdc1, 317 + 50 * symbol_counter_06, 210, x, lstrlen(x));
                                    }
                                    if (tape_06[machine_06_pos - 7 + symbol_counter_06] == 5) {
                                        hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
                                        SelectObject(hdc1, hFont);
                                        TextOut(hdc1, 317 + 50 * symbol_counter_06, 210, TEXT("y"), lstrlen(TEXT("y")));
                                    }
                                }
                            }
                        }
                    }
                    run_checker6 = true;
                }
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: HDC を使用する描画コードをここに追加してください...
            TCHAR title[] = TEXT("Turing Machine");
            TCHAR combo6[] = TEXT("#06用");
            HFONT hFont;
            hFont = CreateFont(30, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
            SelectObject(hdc, hFont);
            TextOut(hdc, 1165, 110, combo6, lstrlen(combo6));
            hFont = CreateFont(50, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, NULL);
            SelectObject(hdc, hFont);
            TextOut( hdc, 530, 40, title, lstrlen(title));
            Rectangle(hdc, 300, 150, 1100, 400);
            Ellipse(hdc, 300, 200, 350, 250);
            Ellipse(hdc, 350, 200, 400, 250);
            Ellipse(hdc, 400, 200, 450, 250);
            Ellipse(hdc, 450, 200, 500, 250);
            Ellipse(hdc, 500, 200, 550, 250);
            Ellipse(hdc, 550, 200, 600, 250);
            Ellipse(hdc, 600, 200, 650, 250);
            Ellipse(hdc, 650, 200, 700, 250);
            Ellipse(hdc, 700, 200, 750, 250);
            Ellipse(hdc, 750, 200, 800, 250);
            Ellipse(hdc, 800, 200, 850, 250);
            Ellipse(hdc, 850, 200, 900, 250);
            Ellipse(hdc, 900, 200, 950, 250);
            Ellipse(hdc, 950, 200, 1000, 250);
            Ellipse(hdc, 1000, 200, 1050, 250);
            Ellipse(hdc, 1050, 200, 1100, 250);
            Ellipse(hdc, 650, 250, 700, 300);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        ReleaseDC(hWnd, hdc1);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


// バージョン情報ボックスのメッセージ ハンドラーです。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
