#include <iostream>
using namespace std;

int* list= nullptr;
int elementNum;

bool isEmpty(){
    if(elementNum==0){
        return true;
    }
    return false;
}
void deleteAllElements(){
    if(elementNum!=0||list!= nullptr){
        delete[]list;
        elementNum = 0;
    }
}

void putLast(int newElement){
    int *tempList = new int[elementNum+1];
    for (int i = 0; i < elementNum; ++i) {
        tempList[i]=list[i];
    }
    tempList[elementNum]=newElement;
    if(list){delete[]list;}
    list=tempList;
    elementNum++;

}

void putFirst(int newElement){
    int *tempList = new int[elementNum+1];
    tempList[0]=newElement;
    for (int i = 0; i < elementNum; ++i) {
        tempList[i+1]=list[i];
    }
    if(list){delete[]list;}
    list=tempList;
    elementNum++;
}

bool changeAtIndex(int index, int newElement){
    if(index<elementNum&&index>=0){
        list[index]=newElement;
        return true;
    }
    else{ return false;}
}

bool changeTwoElements(int firstIndex, int secondIndex){
    if(firstIndex>=0&&firstIndex<elementNum&&
            secondIndex>=0&&secondIndex<elementNum){
        int temp = list[firstIndex];
        list[firstIndex]=list[secondIndex];
        list[secondIndex]=temp;
        return true;
    }
    return false;
}

bool putToIndex(int index,int newElement){
    if(index<0){
        return false;
    }
    else if(index==0){putFirst(newElement);}
    else if(index==elementNum){putLast(newElement);}
    else if(index>elementNum){
        int *tempList = new int[index+1];
        for (int i = 0; i < elementNum; ++i) {
            tempList[i]=list[i];
        }
        for (int j = elementNum; j <index ; ++j) {
            tempList[j]=0;
        }
        tempList[index]=newElement;
        if(list){delete[]list;}
        list=tempList;
        elementNum=index+1;

    }
    else{
        int *tempList = new int[elementNum+1];
        for (int i = 0; i < index; ++i) {
            tempList[i]=list[i];
        }
        tempList[index]=newElement;
        for (int j = index+1; j < elementNum+1; ++j) {
            tempList[j] = list[j-1];
        }
        if(list){delete[]list;}
        list=tempList;
        elementNum++;
    }
    return true;
}

void printListElementsToConsole(){
    for (int i = 0; i < elementNum; ++i) {
        cout<<"The element at ["<<i<<"] is = "<<list[i]<<endl;
    }
    cout<<'\n'<<"-----||-----"<<"\n\n";
}




int main() {
    for (int i = 0; i < 10; ++i) {
        putLast(i);
    }

    printListElementsToConsole();


    for (int j = 0; j < 10; ++j) {
        putFirst(j+10);
    }

    printListElementsToConsole();

    putToIndex(24,145);

    printListElementsToConsole();

    putToIndex(22,8765);

    printListElementsToConsole();

    changeAtIndex(24,100);

    printListElementsToConsole();

    changeTwoElements(22,25);

    printListElementsToConsole();

    deleteAllElements();

    std::cout << "Success!" << std::endl;
    return 0;
}