#include "MMHeader.h"
#include "Matrix.h"
int main()
{
    init_mem(4096);

matrix**mat_array=(matrix**)mem_manager_malloc(10*sizeof(matrix*));
traverse_free_list();
for(int i=1;i<=10;i++)
{
    matrix*mat=matrix_malloc(3,3);
    for (int  j = 1; j <= 3; j++)
    {   
        for (int k = 1; k <= 1; k++)       
        {
            /* code */set_element(mat,j,k,j*k);
        }
        
        mat_array[i-1]=mat;
    }
    
}
for(int i=1;i<=10;i++)
{
    matrix* mat=mat_array[i-1];
    display(mat);
    cout<<"\n"<<endl;
}

traverse_free_list();
matrix_free(mat_array[5]);

traverse_free_list();
matrix_free(mat_array[3]);

traverse_free_list();
matrix_free(mat_array[7]);

traverse_free_list();


cout<<"\nTHIS IS CORRECT TO HERE \n"<<endl;

matrix*mat_1=matrix_malloc(3,5);
display(mat_1);

 void*temp=mem_manager_malloc(64);
 traverse_free_list();


matrix_free(mat_array[2]);

traverse_free_list();
matrix_free(mat_array[9]);

traverse_free_list();
matrix_free(mat_array[0]);
traverse_free_list();

matrix*mat_2=matrix_malloc(5,3);
display(mat_2);
traverse_free_list();


traverse_free_list();

matrix_free(mat_array[4]);

traverse_free_list();

matrix_free(mat_array[6]);

traverse_free_list();
matrix_free(mat_array[8]);

traverse_free_list();
matrix* mult=multiply(mat_1,mat_2);
display(mult);
traverse_free_list();

matrix_free(mat_array[1]);
traverse_free_list();

mem_manager_free(mat_array);
traverse_free_list();

matrix_free(mat_1);
traverse_free_list();
matrix_free(mat_2);
traverse_free_list();
matrix_free(mult);
traverse_free_list();
mem_manager_free(temp);
traverse_free_list();


munmap(head, 4096);
 
return 0;
}