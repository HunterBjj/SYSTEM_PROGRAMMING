#include <iostream>
#include <stdlib.h>
 using namespace std;
 int main()
{
 setlocale(LC_ALL,"RUS");

  long a = rand()%15; // лучше ограничить значение rand от 0 до 14псс
  // long  arr[a]; - нельзя выделять статические массивы, если их длинна не известна на этапе компиляции
 long  *arr = new long[a]; // динамический массив
 long  *ptr = &arr[0];
 long c=a/2;
 long *end_arr= &arr[a-1];
 
 asm(
"mov $1, %%rcx\n\t"
"mov %[ptr], %%rbx\n\t" // Эти две строчки повыше, чтобы не было бесконечного цикла
"mov %[end_arr],%%rax\n\t" //
"loop_start:\n\t"
"mov %%rcx,(%%rbx)\n\t"
"mov %%rcx,(%%rax)\n\t"
"inc %%rcx\n\t"
"add $8,%%rbx\n\t"
"sub $8,%%rax\n\t"
"cmp %%rbx,%%rax\n\t"
"je end_asm\n\t"

"mov %%rax,%%rdx\n\t"
"sub $8,%%rdx\n\t"
"cmp %%rbx,%%rdx\n\t"
"je end_asm\n\t"
"jmp loop_start\n\t"
"end_asm:\n\t"
"mov %%rcx,(%%rbx)\n\t" //Эти две строчки, чтобы добавить значение в центральные элементы
"mov %%rcx,(%%rax)\n\t" // 
:
:[ptr]"m"(ptr),[end_arr]"m"(end_arr)
:"%rax","%rbx","%rcx","%rdx"
);

 cout<<"_________________________________"<<endl;

for(long i = 0;i<a;i++)
{
 cout << "Элемент массива arr[" << i <<"] = "<< arr[i]<<"\n";
}
cout<<endl;
delete [] arr; // освобождение памяти
 return 0;
}
