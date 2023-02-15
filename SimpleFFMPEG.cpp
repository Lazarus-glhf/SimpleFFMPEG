#include <iostream>
using namespace std;

#define FFMPEG_DIR "ThirdParty\\ffmpeg\\bin\\ffmpeg.exe -f image2 -pix_fmt yuv420p "
#define BREAK_STR "****************************************************\n"
#define QUIT 0
#define COMPOSITE_VIDEO 1

string VCODEC = "-vcodec libx264 ";

/*s
ffmpeg -r 60 -f image2 -s 1920x1080 -i fram%d.jpg -vcodec libx264 -crf 25  -pix_fmt yuv420p test.mp4

%04d 表示用零来填充直到长度为4，i.e 0001…0020…0030…2000 and so on. 如果没有填充，需要相应更改，如 pic%d.png or %d.png
-r 帧率(fps)
-f image2 图像合成视频默认设置
-crf 画质，数值小意味着画质高，通常设置为15-25
-s 分辨率（1920x1080）
-pix_fmt yuv420p 像素格式
test.mp4 输出在当前文件夹，输出结果为test.mp4
*/

void CompositeVideo(string FPS, string RESOLUTION, string FRAME_NAME, string AUDIO_PATH, string TARGET_PATH, string CRF)
{
    const string Str = (FFMPEG_DIR + FPS + RESOLUTION + FRAME_NAME + AUDIO_PATH + CRF + VCODEC + TARGET_PATH);
    system(Str.c_str());
}

int main()
{
    int condition = 1;
    while (condition)
    {
        cout << "请选择功能:\n 1 : 合成视频\n 0 : 退出\n ";
        cin >> condition;
        switch (condition)
        {
        case QUIT:
            continue;
        case COMPOSITE_VIDEO:
        {
            string FPS;
            string RESOLUTION;
            string FRAME_NAME;
            string PATH;
            string TARGET_PATH;
            string CRF;
            string AUDIO_PATH;

            cout << BREAK_STR;
            cout << "请输入文件路径，不要有中文。\n 如 D:\\Desktop\\Movie\\ 末尾有斜杠\n";
            cout << BREAK_STR;
            cin >> PATH;
            PATH = "-i " + PATH;
            cout << BREAK_STR;

            cout << "请输入格式化渲染图名称: \n如 SE_StairRoom.00000.jpeg 格式化后为 SE_StairRoom.%05d.jpeg , Bronya0001.png，格式化后为: Bronya%04d.png\n%04d 表示用零来填充直到长度为4, 例如 0001…0020…0030…2000 等。 如果没有填充，需要相应更改，如 pic%d.png 或 %d.png\n";
            cout << BREAK_STR;
            cin >> FRAME_NAME;
            FRAME_NAME = PATH + FRAME_NAME + " ";
            cout << BREAK_STR;

            cout << "请输入音频文件名: \n如 music.wav\n";
            cout << BREAK_STR;
            cin >> AUDIO_PATH;
            AUDIO_PATH = PATH + AUDIO_PATH + " ";
            cout << BREAK_STR;

            cout << "请输入帧率: \n";
            cout << BREAK_STR;
            cin >> FPS;
            FPS = "-r " + FPS + " ";
            cout << BREAK_STR;

            cout << "请输入分辨率: \n例如 1920x1080\n";
            cout << BREAK_STR;
            cin >> RESOLUTION;
            RESOLUTION = "-s " + RESOLUTION + " ";
            cout << BREAK_STR;

            cout << "输出视频质量: \n建议在 10 - 30 之间, 值越小质量越高，文件越大\n";
            cout << BREAK_STR;
            cin >> CRF;
            CRF = "-crf " + CRF + " ";
            cout << BREAK_STR;

            cout << "输出视频文件名称: \n例如 Demo.mp4 Test.flv \n";
            cout << BREAK_STR;
            cin >> TARGET_PATH;
            // TARGET_PATH = PATH + TARGET_PATH;
            cout << BREAK_STR;

            cout << "合成视频中，文件将输出到软件所在路径\n如已存在输出文件已存在请输入 y 覆盖\n";
            cout << BREAK_STR;
            CompositeVideo(FPS, RESOLUTION, FRAME_NAME, AUDIO_PATH, TARGET_PATH, CRF);
        }
        break;
        default:
            break;
        }
    }
    cout << "退出程序中...." << endl;
    // cout << system("ThirdParty\\ffmpeg\\bin\\ffmpeg.exe") << endl;
    system("PAUSE");
    // cout << FFMPEG_DIR << endl;

    return 0;
}