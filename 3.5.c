#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n=10;     //initial cap
struct mte{
	char ***lines;
	int count;
	int cap;
}txtbuff;

//create text buffer:
txtbuff *createtxtbuff(){
	txtbuff *tb = (char *)malloc(sizeof(txtbuff));
	tb.lines = malloc(n*sizeof(char *));
	tb.count=0;
	tb.cap = n;
	return tb;
}

void insert(txtbuff *tb , const char *txt){
	tb.lines[tb.count] = malloc(strlen(txt)+1);
	strcpy(tb.lines[tb.count], txt);
	tb.count++;
}

void dlt(txtbuff *tb, int index) {
    free(tb.lines[index]);
    for (int i = index; i < tb.count - 1; i++)
        tb.lines[i] = tb.lines[i + 1];
    tb.count--;
    printf("Line removed!\n");
}
void display(txtbuff *tb) {
    printf("\n--- Your Text ---\n");
    if (tb.count == 0) {
        printf("(No lines yet!)\n");
    } else {
        for (int i = 0; i < tb.count; i++)
            printf("%d: %s\n", i, tb.lines[i]);
    }
    printf("End of Text");
}
int main(){
txtbuff *tb = createtxtbuff();
    char txt[MAX_LINE];
    int choice, index;
	while(1){
	
	printf("\n1.Insert line\n2.Delete line\n3.Print all lines\n4.Shrink to fit\n5.Save to file\n6.Load from file\n7.Exit\nchoose: ");
	scanf("%d" ,&opt);
	switch(opt){
		case 1:
			printf("enter line to insert:");
			fgets(txt , sizeof(txt) , stdin);
			txt[strcspn(txt, "\n")] = '\0';
            insert(tb , txt);
		break;
		case 2:
			//dlt();
		break;
		case 3:
			//print();
		break;
		case 4:
			//shrink();
		break;
		case 5:
			//save();
		break;
		case 6:
			//load();
		break;
		case 7:
			return 0;
	}
	
}
}

