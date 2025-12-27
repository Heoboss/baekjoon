#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int calDate(vector<int> &possibleNum, int range){
    int result = 0;
    
    for (int i = 0; i < possibleNum.size(); i++){
        if(possibleNum[i] == 0){
                continue;
        }
        result += 1;
        // cout << "date : " << possibleNum[i] << " ";
    }
    
    
    // cout << "\n";
    for(int i = 0; i < possibleNum.size(); i++){
        for(int j = 0; j < possibleNum.size(); j++){
            if(possibleNum[i] == 0){
                continue;
            }
            
            int tmp = stoi(to_string(possibleNum[i]) + to_string(possibleNum[j]));
            if(0 < tmp && tmp <= range){
                result += 1;
                // cout << "date : " << tmp << " ";

            }
        }
    }
    
    return result;
}

int calBirthday(vector<int> &num){
    int result = 0;
    vector<int> possibleNum;
    vector<int> possibleMonth;
    
    map<int, int> rangeDate;
    rangeDate[1] = 31;
    rangeDate[2] = 29;
    rangeDate[3] = 31;
    rangeDate[4] = 30;
    rangeDate[5] = 31;
    rangeDate[6] = 30;
    rangeDate[7] = 31;
    rangeDate[8] = 31;
    rangeDate[9] = 30;
    rangeDate[10] = 31;
    rangeDate[11] = 30;
    rangeDate[12] = 31;
    
    for(int i = 0; i < num.size(); i++){
        if(num[i] == 0){
            possibleNum.push_back(i);
        }
    }
    
    // for(int num : possibleNum){
    //     cout << num << " ";
    // }
    
    for (int i = 0; i < possibleNum.size(); i++){
        if(possibleNum[i] == 0){
                continue;
        }
        possibleMonth.push_back(possibleNum[i]);
    }
    
    // 2. 월 조합 계산 - 두자리수
    for(int i = 0; i < possibleNum.size(); i++){
        for(int j = 0; j < possibleNum.size(); j++){
            if(possibleNum[i] == 0){
                continue;
            }
            
            int tmp = stoi(to_string(possibleNum[i]) + to_string(possibleNum[j]));
            if(0 < tmp && tmp <= 12){
                possibleMonth.push_back(tmp);
            }
        }
    }
    
    // for(int month : possibleMonth){
    //     cout << month << " ";
    // }
    
    for(int i = 0; i < possibleMonth.size(); i++){
        result += calDate(possibleNum, rangeDate[possibleMonth[i]]);
    }
    
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    vector<int> num(10, 0);
    
    //입력 
    cin >> t;
    
    //연산
    while(t > 0){
        for(int i = 0; i < 10; i++){
            cin >> num[i];
        }
        
        //출력
        cout << calBirthday(num) << "\n";
        
        t--;
    }

    return 0;
}