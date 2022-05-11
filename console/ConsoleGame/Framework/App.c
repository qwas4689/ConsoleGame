#include "App.h"
#include "Common.h"
#include "Renderer.h"
#include "Timer.h"

bool App_Init()
{
    if (false == Renderer_Init())
    {
        return false;
    }

    return true;
}

void processInput()
{

}

float elapsedTime;
bool canShow = false;
void update()
{
    /*
    // ��ʽ�
    // ������ : �ð�
    // 1 : deltaTime = fps : 1
    // 1 = deltaTime * fps
    // fps = 1 / deltaTime
    char str[128] = "";
    sprintf_s(str, sizeof(str), "���� FPS : %d", (int32)(1 / Timer_GetDeltaTime()));
    Renderer_DrawText(str, strlen(str));
    */

    // 0.5�� ���� �����̴� �ؽ�Ʈ�� ����ÿ�.
    elapsedTime += DELTA_TIME;

    if (elapsedTime >= 0.5f)
    {
        elapsedTime = 0.0f;
        canShow = !canShow;
    }

    if (canShow)
    {
        Renderer_DrawText("�� �ؽ�Ʈ�� �����Դϴ�.", sizeof("�� �ؽ�Ʈ�� �����Դϴ�."));
    }
    

}

void render()
{
    Renderer_Flip();
}

void cleanup()
{
    Renderer_Cleanup();
}

int32 App_Run()
{
    atexit(cleanup);

    Timer_Init(60);


    // Game Loop : ������ ���۽�Ű�� ����. ������(Frame)�̶�� �Ѵ�.
    while (true)
    {
        // �ð��� ������Ʈ ���� ������ ���� ���� ����
        if (Timer_Update()) 
        {
            processInput();      // �Է� ó��
            update();         // ���� ������Ʈ
            render();         // ���� ���
        }
    }

    return 0;
}