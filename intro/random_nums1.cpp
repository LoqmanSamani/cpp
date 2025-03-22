#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<algorithm>

int main (){

    std::vector <int> win = {1, 3, 5, 7, 9};
    int win_count = 0;
    int nwin_count = 0;
    
    srand(time(0));
    

    for (int i = 1; i <= 10000; i++){

        int rand_num = rand() % 10 + 1;

        switch(rand_num){
            case 1: std::cout <<       "Congrats! you won :)" << std::endl; break;
            case 2: std::cout <<  "Sorry! you did not win :(" << std::endl; break;
            case 3: std::cout <<       "Congrats! you won :)" << std::endl; break;
            case 4: std::cout <<  "Sorry! you did not win :(" << std::endl; break;
            case 5: std::cout <<       "Congrats! you won :)" << std::endl; break;
            case 6: std::cout <<  "Sorry! you did not win :(" << std::endl; break;
            case 7: std::cout <<       "Congrats! you won :)" << std::endl; break;
            case 8: std::cout <<  "Sorry! you did not win :(" << std::endl; break;
            case 9: std::cout <<       "Congrats! you won :)" << std::endl; break;
            case 10: std::cout << "Sorry! you did not win :(" << std::endl; break;
        }
        if (std::find(win.begin(), win.end(), rand_num) != win.end()){
            win_count++;

        } else{
            nwin_count++;
        }
    }

    std::cout << "Your wining chance is " << (double) win_count / (win_count + nwin_count) << " %" << std::endl;

    return 0;
}