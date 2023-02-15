#include <iostream>
using namespace std;

#define FFMPEG_DIR "ThirdParty\\ffmpeg\\bin\\ffmpeg.exe -f image2 -pix_fmt yuv420p "
#define BREAK_STR "****************************************************\n"
#define QUIT 0
#define COMPOSITE_VIDEO 1

string VCODEC = "-vcodec libx264 ";

/*s
ffmpeg -r 60 -f image2 -s 1920x1080 -i fram%d.jpg -vcodec libx264 -crf 25  -pix_fmt yuv420p test.mp4

%04d ��ʾ���������ֱ������Ϊ4��i.e 0001��0020��0030��2000 and so on. ���û����䣬��Ҫ��Ӧ���ģ��� pic%d.png or %d.png
-r ֡��(fps)
-f image2 ͼ��ϳ���ƵĬ������
-crf ���ʣ���ֵС��ζ�Ż��ʸߣ�ͨ������Ϊ15-25
-s �ֱ��ʣ�1920x1080��
-pix_fmt yuv420p ���ظ�ʽ
test.mp4 ����ڵ�ǰ�ļ��У�������Ϊtest.mp4
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
        cout << "��ѡ����:\n 1 : �ϳ���Ƶ\n 0 : �˳�\n ";
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
            cout << "�������ļ�·������Ҫ�����ġ�\n �� D:\\Desktop\\Movie\\ ĩβ��б��\n";
            cout << BREAK_STR;
            cin >> PATH;
            PATH = "-i " + PATH;
            cout << BREAK_STR;

            cout << "�������ʽ����Ⱦͼ����: \n�� SE_StairRoom.00000.jpeg ��ʽ����Ϊ SE_StairRoom.%05d.jpeg , Bronya0001.png����ʽ����Ϊ: Bronya%04d.png\n%04d ��ʾ���������ֱ������Ϊ4, ���� 0001��0020��0030��2000 �ȡ� ���û����䣬��Ҫ��Ӧ���ģ��� pic%d.png �� %d.png\n";
            cout << BREAK_STR;
            cin >> FRAME_NAME;
            FRAME_NAME = PATH + FRAME_NAME + " ";
            cout << BREAK_STR;

            cout << "��������Ƶ�ļ���: \n�� music.wav\n";
            cout << BREAK_STR;
            cin >> AUDIO_PATH;
            AUDIO_PATH = PATH + AUDIO_PATH + " ";
            cout << BREAK_STR;

            cout << "������֡��: \n";
            cout << BREAK_STR;
            cin >> FPS;
            FPS = "-r " + FPS + " ";
            cout << BREAK_STR;

            cout << "������ֱ���: \n���� 1920x1080\n";
            cout << BREAK_STR;
            cin >> RESOLUTION;
            RESOLUTION = "-s " + RESOLUTION + " ";
            cout << BREAK_STR;

            cout << "�����Ƶ����: \n������ 10 - 30 ֮��, ֵԽС����Խ�ߣ��ļ�Խ��\n";
            cout << BREAK_STR;
            cin >> CRF;
            CRF = "-crf " + CRF + " ";
            cout << BREAK_STR;

            cout << "�����Ƶ�ļ�����: \n���� Demo.mp4 Test.flv \n";
            cout << BREAK_STR;
            cin >> TARGET_PATH;
            // TARGET_PATH = PATH + TARGET_PATH;
            cout << BREAK_STR;

            cout << "�ϳ���Ƶ�У��ļ���������������·��\n���Ѵ�������ļ��Ѵ��������� y ����\n";
            cout << BREAK_STR;
            CompositeVideo(FPS, RESOLUTION, FRAME_NAME, AUDIO_PATH, TARGET_PATH, CRF);
        }
        break;
        default:
            break;
        }
    }
    cout << "�˳�������...." << endl;
    // cout << system("ThirdParty\\ffmpeg\\bin\\ffmpeg.exe") << endl;
    system("PAUSE");
    // cout << FFMPEG_DIR << endl;

    return 0;
}