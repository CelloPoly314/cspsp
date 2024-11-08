#include "../include/JTextInput.h"

using namespace std;

JGE* JTextInput::mEngine = NULL;

JTextInput::JTextInput()
{
    mEngine = JGE::GetInstance();
    mIsActive = false;
    mString = "";
}

JTextInput::~JTextInput()
{
}

void JTextInput::Enable()
{
    mIsActive = true;
    mString = "";
}

void JTextInput::Disable()
{
    mIsActive = false;
}

void JTextInput::Update(float dt)
{
    string input = mEngine->GetTextInput();
    mString += input;

    static float gKeyRepeatDelay = 800;  // 初始化延迟为 800ms
    static bool isCircleHeld = false;    // 用于跟踪 Circle 按钮是否按下

    // 检查 Circle 按键的状态
    if (mEngine->GetButtonState(PSP_CTRL_CIRCLE)) {
        if (!isCircleHeld) {  // 如果刚按下 Circle 键，首先执行一次删除操作
            mString = mString.substr(0, mString.size() - 1);  // 删除一个字符
            gKeyRepeatDelay = 800;  // 设置初始延迟为 800ms
            isCircleHeld = true;
        }

        // 延迟倒计时
        gKeyRepeatDelay -= dt;

        if (gKeyRepeatDelay <= 0.0f) {
            // 延迟到达 0，执行删除操作
            mString = mString.substr(0, mString.size() - 1);
            gKeyRepeatDelay = 50;  // 设置重复延迟为 50ms
        }
    }
    else {
        // 如果 Circle 键没有被按下，重置延迟为 800ms
        isCircleHeld = false;
        gKeyRepeatDelay = 800;
    }
}


void JTextInput::Render(float x, float y)
{

}