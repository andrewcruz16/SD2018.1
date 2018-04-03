#include <iostream>
#include <signal.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void manSinal(int idSinal) {                                    //tratamento do sinal recebido
    cout << "Signal received: " << idSinal << endl;
    if (idSinal == 1) {
        exit(0);  
    }
}

int main(int argc, const char * argv[]) {
    signal(17, manSinal);                                       //SIGSTOP
    signal(19, manSinal);                                       //SIGCONT
    signal(1, manSinal);                                        //SIGHUP

    int espera = atoi(argv[1]);
    switch(espera){
        case 1:
            while(1) {
                cout << "Busy waiting process number " << getpid() << endl;
                sleep(1);
            }
            break;
        case 2:
        default:
            while(1) {
                cout << "Blocking waiting process number " << getpid() << endl;
                pause();
            }
            break;
    }

    return EXIT_SUCCESS;
}