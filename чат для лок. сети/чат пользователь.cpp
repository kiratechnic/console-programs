#pragma comment(lib, ws2_32.lib)
#includewinsock2.h
#includeiostream
#pragma warning(disable 4996)
enum ConsoleColor {
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background  4)  text));
}
void GotoXY(int X, int Y)
{
    HANDLE hConsole;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}
using namespace std;

int main()
{
    char msg[32];
    char msg_catch[32];
    char ip_server[10]{};
    char ip_local[13]{ 192.168.3.93};
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 2);
    WSAStartup(DLLVersion, &wsaData);

    if (WSAStartup(DLLVersion, &wsaData) != 0)
    {
        cout  error  endl;
        exit(1);
    }

    char choice_login_registr;


    SOCKADDR_IN addr;
    int sizeofaddr = sizeof(addr);
    system(cls);

    addr.sin_addr.s_addr = inet_addr(ip_local);
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;
    SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
    if (connect(Connection, (SOCKADDR)&addr, sizeof(addr)) != 0)
    {
        cout  error failed connect to server.n;
        return 1;
    }
    else
    {
        SetColor(2, 0);
        cout  Connected!n;
        SetColor(15, 0);
        while (true)
        {
            while (true)
            {
                cout  enter your msg --n;
                cin  msg;
                send(Connection, msg, sizeof(msg), NULL);
                recv(Connection, msg_catch, sizeof(msg_catch), NULL);
                SetColor(4, 0);
                cout  message from the another user--  msg_catch  endl;
                SetColor(15, 0);
                if (msg == 0)
                {
                    break;
                    SetColor(4, 0);
                    cout  you have disconnectedn;
                    SetColor(15, 0);
                    system(pause);
                }
            }

        }
        system(pause);
    }
}