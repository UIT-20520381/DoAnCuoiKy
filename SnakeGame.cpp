#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include<vector>

#define CAO 20
#define RONG 40
using namespace std;

void gotoxy(int column, int line);
struct Point {
    int x, y;
};

vector<Point> A = {
     Point{ RONG / 2 + 2, CAO / 2 },
     Point{ RONG / 2 + 1, CAO / 2 },
     Point{ RONG / 2, CAO / 2 },
     Point{RONG / 2 - 1,CAO / 2 }
    };

Point Moi;
int Diem = 0;
Point duoi;

class CONRAN;
void MenuBatDau();
void VeTuong();
bool DungTuong();
void KhoiTaoMoi();
bool AnMoi();
void LonLen();
bool TuCanMinh();
void BangDiem();
void ResetRan();
void BatDau();
void XuLyThua();
void MenuBatDau();
void XoaConTro();



class CONRAN {
public:
    void Ve() {
        for (int i = 0; i < A.size(); i++) {
            gotoxy(A[i].x, A[i].y);
            cout << "X";
        }
    }
    void DiChuyen(int Huong) {
        duoi = A.back();
        for (int i = A.size() - 1; i > 0; i--)
            A[i] = A[i - 1];
        if (Huong == 0) A[0].x = A[0].x + 1;
        if (Huong == 1) A[0].y = A[0].y + 1;
        if (Huong == 2) A[0].x = A[0].x - 1;
        if (Huong == 3) A[0].y = A[0].y - 1;
    }
    void XoaDuoi()
    {
        gotoxy(duoi.x, duoi.y);
        cout << " ";
    }
};

void VeTuong()
{
    for (int i = 0; i < RONG; i++)
        cout << (char)220;
    gotoxy(0, CAO);
    for (int i = 0; i < RONG; i++)
        cout << (char)223;
    for (int i = 1; i < CAO; i++)
    {
        gotoxy(0, i);
        cout << (char)221;
    }
    for (int i = 1; i < CAO; i++)
    {
        gotoxy(RONG - 1, i);
        cout << (char)222;
    }
}

bool DungTuong()
{
    return A[0].x == 0 || A[0].y == 0 || A[0].x == RONG || A[0].y == CAO;
}

void KhoiTaoMoi()
{
    srand(time(0));
    int x = rand() % (RONG - 2) + 1;
    int y = rand() % (CAO - 2) + 1;
    Moi = {
        x,
        y,
    };
    gotoxy(x, y);
    cout << (char)4;
}

bool AnMoi()
{
    return A[0].x == Moi.x && A[0].y == Moi.y;
}

void LonLen()
{
    A.push_back(duoi);
}

bool TuCanMinh()
{
    Point dau = A[0];
    for (int i = 1; i < A.size(); i++)
        if (dau.x == A[i].x && dau.y == A[i].y)
            return true;
    return false;
}

void BangDiem()
{
    gotoxy(RONG + 5, 2);
    cout << "Diem cua ban: " << Diem;
}

void ResetRan()
{
    Diem = 0;
    A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    A = {
    Point{ RONG / 2 + 2, CAO / 2 },
    Point{ RONG / 2 + 1, CAO / 2 },
    Point{ RONG / 2, CAO / 2 },
    Point{RONG / 2 - 1,CAO / 2 }
    };
    
}

void BatDau()
{
    system("cls");
    CONRAN r;
    int Huong = 0;
    char t;
    VeTuong();
    KhoiTaoMoi();
    BangDiem();
    XoaConTro();
    while (1) {
        if (_kbhit()) {
            t = _getch();
            if (t == 'a') Huong = 2;
            if (t == 'w') Huong = 3;
            if (t == 'd') Huong = 0;
            if (t == 's') Huong = 1;
        }
        r.Ve();
        r.DiChuyen(Huong);
        r.XoaDuoi();
        Sleep(300);
        if (AnMoi())
        {
            Diem++;
            BangDiem();
            LonLen();
            KhoiTaoMoi();
        }

        if (DungTuong()==true||TuCanMinh()==true)
        {
            XuLyThua();
            break;
        }
    }
}

void XuLyThua()
{
    system("cls");
    gotoxy(0, 0);
    cout << "Ket thuc!" << endl;
    cout << "Diem cua ban la: " << Diem << endl;
    cout << "Ban co muon thu lai? ([y]/[n]): ";
    char option;
    cin >> option;
    if (option == 'y')
    {
        ResetRan();
        Diem = 0;
        BatDau();
        
    }
    else if (option == 'n')
    {
        system("cls");
        cout << "Hen gap lai ^.^" << endl;
        exit(1);
    }
}

void MenuBatDau()
{
    system("cls");
    cout << "Chao mung ban den voi game Ran san Moi!" << endl;
    cout << "Luat choi: dung cac phim w,s,a,d de dieu khien ran len,xuong,trai,phai va an moi" << endl;
    cout << "Lua chon:" << endl;
    cout << "1.Bat Dau" << endl;
    cout << "2.Ket thuc" << endl;
    cout << "Lua chon cua ban: ";
    int luachon;
    cin >> luachon;
    if (luachon == 1)
    {
        system("cls");
        cout << "Chuan Bi";
        Sleep(1000);
        for (int i = 3; i > 0; i--)
        {
            gotoxy(0, 3);
            cout << i << " ";
            Sleep(1000);
        }
        gotoxy(0, 3);
        cout << "GO!";
        Sleep(1000);
        BatDau();

    }
    else if (luachon == 2)
        exit(1);
}

int main()
{
    MenuBatDau();
    return 0;
}

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord
    );
}

void XoaConTro()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
