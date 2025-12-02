#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nm[100];
    char bch[50];
    char mem[10];
    char reg[20];
    char bd[20];
    char intst[10];
} Stu;

Stu *arr = NULL;
int cnt = 0;
int cap = 0;
const char *fname = "db.dat";

void ldDB(const char *f) {
    FILE *fptr = fopen(f, "rb");
    if (!fptr) {
        printf("No db found.\n");
        return;
    }

    fseek(fptr, 0, SEEK_END);
    long sz = ftell(fptr);
    rewind(fptr);
    int n = sz / sizeof(Stu);
    if (n <= 0) { fclose(fptr); return; }

    arr = malloc(n * sizeof(Stu));
    if (!arr) { perror("malloc fail"); fclose(fptr); exit(1); }
    cap = n;
    cnt = n;

    if (fread(arr, sizeof(Stu), n, fptr) != n)
        perror("read error");
    fclose(fptr);
}

void svDB(const char *f) {
    FILE *fptr = fopen(f, "wb");
    if (!fptr) { perror("write error"); return; }
    if (fwrite(arr, sizeof(Stu), cnt, fptr) != cnt)
        perror("write fail");
    fclose(fptr);
}

int findIdx(int sid) {
    for (int i=0;i<cnt;i++)
        if (arr[i].id==sid) return i;
    return -1;
}

int addStu(Stu s) {
    if (findIdx(s.id)!=-1) { printf("ID exists\n"); return 0; }

    if (cnt==cap) {
        int nc = (cap==0)?5:cap*2;
        Stu *t = realloc(arr, nc*sizeof(Stu));
        if (!t) { perror("realloc fail"); return 0; }
        arr = t;
        cap = nc;
    }
    arr[cnt++] = s;
    return 1;
}

void updStu(int sid) {
    int i = findIdx(sid);
    if (i==-1) { printf("ID not found\n"); return; }

    char buf[1024];
    printf("Batch[%s]: ", arr[i].bch);
    fgets(buf, 1024, stdin);
    buf[strcspn(buf,"\n")]='\0';
    strcpy(arr[i].bch, buf);

    printf("Membership[%s]: ", arr[i].mem);
    fgets(buf, 1024, stdin);
    buf[strcspn(buf,"\n")]='\0';
    strcpy(arr[i].mem, buf);

    printf("Updated!\n");
}

void delStu(int sid) {
    int i = findIdx(sid);
    if (i==-1) { printf("Not found\n"); return; }
    for (int j=i;j<cnt-1;j++)
        arr[j]=arr[j+1];
    cnt--;
    printf("Deleted\n");
}

void showAll() {
    if(cnt==0) { printf("Empty\n"); return; }
    printf("\n---ALL---\n");
    for(int i=0;i<cnt;i++){
        Stu x = arr[i];
        printf("ID:%d Name:%s Batch:%s Mem:%s Reg:%s DOB:%s Int:%s\n",
            x.id, x.nm, x.bch, x.mem, x.reg, x.bd, x.intst);
    }
}

void batchRpt() {
    char b[50], m[10];
    printf("Batch? "); fgets(b,50,stdin); b[strcspn(b,"\n")]=0;
    printf("Interest? "); fgets(m,10,stdin); m[strcspn(m,"\n")]=0;
    int f=0;
    printf("\n---Report---\n");
    for(int i=0;i<cnt;i++){
        if(strcmp(arr[i].bch,b)==0 && (strcmp(arr[i].intst,m)==0 || strcmp(m,"Both")==0)){
            Stu x = arr[i];
            printf("ID:%d Name:%s Mem:%s Reg:%s DOB:%s Int:%s\n",
                x.id,x.nm,x.mem,x.reg,x.bd,x.intst);
            f=1;
        }
    }
    if(!f) printf("None\n");
}

void freeMem(){
	
void freeMem() {
    free(arr);
}
}

int main() {
    ldDB(fname);
    int choice;

    while(1){
	
        printf("1.Register New-Student\n");
        printf("2.Update Student\n");
        printf("3.Delete Student\n");
        printf("4.View All\n");
        printf("5.Batch-Wise Report\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
switch(choice){
        case 1:{
		
            Stu s;
            char buf[1024];

            printf("\n\t---STUDENT REGISTERATION---\n");
            printf("Enter Student ID: ");
            scanf("%d", &s.id);
            getchar();

            printf("Full Name: ");
            fgets(buf, 1024, stdin);
            buf[strcspn(buf, "\n")] = '\0';
            strcpy(s.nm, buf);

            printf("Batch (CS/SE/Cyber Security/AI): ");
            fgets(buf, 1024, stdin);
            buf[strcspn(buf, "\n")] = '\0';
            strcpy(s.bch, buf);

            printf("Membership Type (IEEE/ACM): ");
            fgets(buf, 1024, stdin);
            buf[strcspn(buf, "\n")] = '\0';
            strcpy(s.mem, buf);

            printf("Registration Date (DD-MM-YYYY): ");
            fgets(buf, 1024, stdin);
            buf[strcspn(buf, "\n")] = '\0';
            strcpy(s.reg, buf);

            printf("Date of Birth (DD-MM-YYYY): ");
            fgets(buf, 1024, stdin);
            buf[strcspn(buf, "\n")] = '\0';
            strcpy(s.bd, buf);
            printf("Interest (IEEE/ACM/Both): ");
            fgets(buf, 1024, stdin);
            buf[strcspn(buf, "\n")] = '\0';
            strcpy(s.intst, buf);

            if (addStu(s)) {
                printf("Student registered successfully.\n");
                svDB(fname);
            }
        break;
		}
       case 2: {
                int id;
				 printf("ID? "); 
				scanf("%d",&id);
				 getchar(); 
				 updStu(id); 
				 svDB(fname);
                break;
            }
            case 3: {
                int id; 
				printf("ID?");
				 scanf("%d",&id);
				  getchar();
				   delStu(id); 
				   svDB(fname);
                break;
            }
            case 4:
			 showAll();
			 
			  break;
            case 5:
			 batchRpt();
			  break;
            case 6: 
			printf("Bye!\n");
			return 0;
			break;
        default:
            printf("Invalid choice.\n");
            
    }
}

    freeMem();
    return 0;
}
