/*ANIL AKBULUT 151044029 HW06*/
#include <stdio.h>
#define NUM_STR 1000
#define NUM_SORT 100

/*specified functions used*/
int common(int num1,int num2,int div); /*Part1 function*/
void formula_f(int num); /*Part3 function*/
int equality(int num,int *p,int *b); /*Part4 function*/
char find_cap_let(char *input); /*Part5 function*/
int partial_arr(int p[],int tail); /*Part2 function*/
void compare_arrs(int p[],int a1[],int a2[],int a1_size,int a2_size);/*Part2 function*/

/*The compare function compares 2 array*/
void compare_arrs(int p[], /*p array is main array*/
				  int a1[],/*The a1 array consists of the first half of the element.*/
				  int a2[],/*The a2 array consists of the second half of the element.*/
				  int a1_size,/*Number of elements of a1*/
				  int a2_size){ /*Number of elements of a2*/
	int i,j,temp;
	for(i=0;i<a1_size;i++) p[i]=a1[i]; /*The elements of a1 and a2 combine.*/
	for(j=0;j<a2_size;j++){
		p[i]=a2[j];
		i++;
	}
	for(i=0;i<a1_size+a2_size-1;i++){ /*The elements of a1 and a2 compare.*/
		for(j=i+1;j<a1_size+a2_size;j++){
			if(p[i]>p[j]){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}

int partial_arr(int p[],/*p array is a main array*/
				int tail){/*tail is the number of elements of p*/
	if(tail/2==0) return 0; /*The return condition of the tail/2 is equal 0*/
	int a1[tail/2];
	int a2[tail-tail/2];
	int i,j;
	for(i=0;i<tail/2;i++) a1[i]=p[i];
	for(j=0;j<tail-tail/2;j++){
		a2[j]=p[i];
		i++;
	}
	partial_arr(a1,tail/2);/*first half of p*/
	partial_arr(a2,tail-tail/2);/*, then second half of p.*/
	compare_arrs(p,a1,a2,tail/2,tail-tail/2);/*then compare*/
}
/*The find_cap_let is find first capital letter*/
char find_cap_let(char *input){ 
	if(input[0]==0) return 0; /*if input is NULL,return 0*/
	if(input[0]<=90 && input[0]>=65){ /*if the letter is between 95 and 60, it has a capital letter.*/
		return input[0]; /*and return capital letter*/
	}
	else find_cap_let(input+1);/*if the element of the array is lowercase, the next element is checked*/
}
/*This function has the value of each digit until the leftmost digit.*/
/*As the function returns, the pow process is applied in total.*/
int equality(int num, /*num is a input*/
			 int *p,/*p is value (=0)*/
			 int *b){/*The variable b stores the number of digits of the number */
	int sum=1,res=0,temp;
	int a=*p+1;
	int digit=num%10;
	if(num<0) return 0;
	if(num!=0) res += equality(num/10,&a,b);
	if(num==0) *b=a;
	temp=*b;
	while(temp>1){
		sum *= digit;
		temp--;
	}
	if(num==0) return 0;
	return sum+res;
}
/*The formula_f function executes the required operations until the number is 1*/
void formula_f(int num){
	printf("%d ",num );
	if(num<=1){ /*if the number is single function is return.*/
		return;
	}
	if(num%2==0){ /*if the number is even again formula_f execute*/
		formula_f(num/2);
	}
	else{
		formula_f(3*num + 1);/*if the number is odd again formula_f execute*/
	}
}
/*The common function finds the largest common divisor of 2 numbers.*/
int common(int num1,int num2,int div){
	if(num1==num2) return num1;
	if(num1==0 || num2==0 ) return 0;
	if(div>num1 || div>num2){
		return 1;
	}
	if(num1%div==0 && num2%div==0){
		div *= common(num1/div,num2/div,div);
	}
	else{
		div = common(num1,num2,div+1);
	}
	return div;
}

void main()
{
	int menu; // choice
	int num1,num2; // part1
	int sort[NUM_SORT],list,i=0; // part2
	int num3; // part 3
	int num4; // part4
	int p=0,b;//part4
	char input[NUM_STR]; // part5
	do{
		printf("Menu:\n");
		printf("1.Part1\n");
		printf("2.Part2\n");
		printf("3.Part3\n");
		printf("4.Part4\n");
		printf("5.Part5\n");
		printf("0.Exit\n");
		scanf("%d",&menu);/*User selects action*/
		switch(menu){
			case 0: break;
			case 1:
					do{
						printf("Enter number 1 and number 2 : ");
						scanf("%d%d",&num1,&num2);			
					}while(num1<0 || num2<0);/*if the entered numbers are negative, you are asked to enter the number again*/
					printf("Common factors (%d , %d) = %d\n",num1,num2,common(num1,num2,2));
					break;
			case 2:	printf("Enter the lenght of the list: ");
					scanf("%d",&list);
					printf("Enter the elements of list: ");
					for(i=0;i<list;i++) scanf("%d",&sort[i]);
					partial_arr(sort,list);
					for(i=0;i<list;i++) printf("%d ",sort[i] );
					printf("\n");
					break;
			case 3:
				    printf("Input : " );
				    scanf("%d",&num3);
				    printf("Output : ");
					formula_f(num3);
					printf("\n");
					break;
			case 4:
					printf("Input : ");
					scanf("%d",&num4);
					if(num4==equality(num4,&p,&b)){
						printf("Output : Equal\n");
					}
					else printf("Output : Not Equal\n");
					break;
			case 5:
					printf("Input : ");
					scanf("%s",input);
					printf("Output : %c\n",find_cap_let(input));
					break;
			default:
					printf("Incorrect choice\n"); /*Error message*/
					break;
		}
		printf("\n");
	}while(menu!=0);/*If user chooses 0,program is finis*/
}