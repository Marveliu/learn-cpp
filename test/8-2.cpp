#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iostream>
#include <string>
#include <deque>
#include <numeric>
using namespace std;

class player
{
  public:
    string name;
    float score[3];
};

// 模拟参赛人员
int Genplayer(map<int, player> &m, vector<int> &v)
{
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    random_shuffle(str.begin(), str.end());

    for (int i = 0; i < 24; i++)
    {
        player tmp;
        tmp.name = "player";
        tmp.name = tmp.name + str[i];
        m.insert(pair<int, player>(100 + i, tmp));
    }

    for (int i = 0; i < 24; i++)
    {
        v.push_back(100 + i);
    }
    return 0;
}

int speech_contest_draw(vector<int> &v)
{
    random_shuffle(v.begin(), v.end());
    return 0;
}

int speech_contest(int index, vector<int> &v, map<int, player> &m, vector<int> &v2)
{
    //小组的比赛得分 记录下来 求出前三名 后三名
    multimap<int, int, greater<int> > mm; //按照key从大到小排列
    int tmpCount = 0;
    int num = 1;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        tmpCount++;
        {
            // 模拟评分
            deque<int> dscore;
            for (int i = 0; i < 10; i++)
            {
                int score = 50 + rand() % 51;
                dscore.push_back(score);
            }
            //对得分排序 去最高 最低
            sort(dscore.begin(), dscore.end());
            dscore.pop_back();  //去最低分
            dscore.pop_front(); //去最高分
            //求平均
            int sum = accumulate(dscore.begin(), dscore.end(), 0);
            float average = sum / dscore.size();
            //选手得分存
            m[*it].score[index] = average;
            mm.insert(pair<int, int>(average, *it)); //平均分 编号
        }

        //处理分组
        if (tmpCount % 6 == 0)
        {
            cout << "no\t"
                 << "name\t"
                 << "score" << endl;
            for (multimap<int, int, greater<int> >::iterator mit = mm.begin(); mit != mm.end(); mit++)
            {
                cout << mit->second << "\t" << m[mit->second].name << "\t" << m[mit->second].score[index] << endl;
            }

            //前三名存入v2 晋级 遍历容器
            while (mm.size() > 3)
            {
                multimap<int, int, greater<int> >::iterator it = mm.begin();
                v2.push_back(it->second); //前三名晋级
                mm.erase(it);
            }
            mm.clear();
            num++;
        }
    }
    return 0;
};
int result(int index, vector<int> &v, map<int, player> &m)
{
    cout << "round" << index + 1 << "result:" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "\t" << m[*it].name << "\t" << m[*it].score[index] << endl;
    }
    return 0;
}

void show()
{
    map<int, player> mapplayer; //所有参赛选手名单

    vector<int> v1; //第1轮演讲比赛名单
    vector<int> v2; //第2轮演讲比赛名单
    vector<int> v3; //第3轮演讲比赛名单
    vector<int> v4; //演讲名单

    //产生选手 得到第1轮选手比赛名单
    Genplayer(mapplayer, v1);

    //第1轮 选手抽签 选手比赛 查看结果
    cout << "roud 1" << endl;
    speech_contest_draw(v1);
    speech_contest(0, v1, mapplayer, v2);
    result(0, v2, mapplayer);

    cout << "roud 2" << endl;
    speech_contest_draw(v2);
    speech_contest(1, v2, mapplayer, v3);
    result(1, v3, mapplayer);

    cout << "roud 3" << endl;
    speech_contest_draw(v3);
    speech_contest(2, v3, mapplayer, v4);
    result(2, v4, mapplayer);
}

int main()
{
    show();
    return 0;
}

// roud 1
// no      name    score
// 117     playerY 72
// 116     playerT 72
// 109     playerZ 71
// 115     playerE 70
// 112     playerV 66
// 100     playerW 61
// no      name    score
// 123     playerN 81
// 114     playerL 79
// 101     playerP 77
// 118     playerU 70
// 102     playerO 69
// 119     playerD 66
// no      name    score
// 108     playerH 78
// 106     playerJ 76
// 107     playerM 73
// 105     playerQ 73
// 104     playerF 73
// 120     playerS 73
// no      name    score
// 121     playerA 84
// 111     playerB 84
// 110     playerR 83
// 103     playerI 74
// 122     playerC 73
// 113     playerX 68
// round1result:
// 117     playerY 72
// 116     playerT 72
// 109     playerZ 71
// 123     playerN 81
// 114     playerL 79
// 101     playerP 77
// 108     playerH 78
// 106     playerJ 76
// 107     playerM 73
// 121     playerA 84
// 111     playerB 84
// 110     playerR 83
// roud 2
// no      name    score
// 107     playerM 77
// 110     playerR 76
// 114     playerL 75
// 101     playerP 74
// 108     playerH 73
// 109     playerZ 66
// no      name    score
// 117     playerY 84
// 121     playerA 79
// 106     playerJ 76
// 111     playerB 72
// 123     playerN 66
// 116     playerT 61
// round2result:
// 107     playerM 77
// 110     playerR 76
// 114     playerL 75
// 117     playerY 84
// 121     playerA 79
// 106     playerJ 76
// roud 3
// no      name    score
// 110     playerR 82
// 121     playerA 80
// 106     playerJ 80
// 117     playerY 75
// 114     playerL 67
// 107     playerM 64
// round3result:
// 110     playerR 82
// 121     playerA 80
// 106     playerJ 80