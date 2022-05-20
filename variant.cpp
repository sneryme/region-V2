#include "variant.h"
#include "Create_table.h"
#include "sort.h"
#include "Reade_file.h"


void MainWindow::enter(struct Vibor,int choice){

        int check;
        switch(choice){
        case 0:
            check=Read_file(Vibor1.filePath, Vibor1.Region, Vibor1.lis);
            break;
        case 1:
             check=Create_table(Vibor1.lis);
            break;
        case 2:
            Sort(Vibor1.stolb,Vibor1.lis,Vibor1.rez);
           break;
        default:
            break;
    }
}
