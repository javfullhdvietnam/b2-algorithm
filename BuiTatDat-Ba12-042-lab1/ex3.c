#include <stdio.h>

struct Complex
{
    float real;
    float imge;
};

struct Complex addtionComplex(struct Complex num1, struct Complex num2){
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imge = num1.imge + num2.imge;
    return result;
}

struct Complex MultpliComelex(struct Complex num1, struct Complex num2)
{
    struct Complex result;
    result.real = num1.real*num2.real - num1.imge*num2.imge;
    result.imge = num1.real*num2.imge + num1.imge*num2.real;
    return result;
}
void display(struct Complex num){
    printf("%.2f + %.2fi",num.real,num.imge);
}


int main(){
    struct Complex ComplexNum1, ComplexNum2, Sumresult, Productresult;

    printf("input complex number1: ");
    scanf("%f %f",&ComplexNum1.real , &ComplexNum1.imge);
    printf("input complex number2: ");
    scanf("%f %f", &ComplexNum2.real, &ComplexNum2.imge);

    
    Sumresult = addtionComplex(ComplexNum1,ComplexNum2);
    Productresult = MultpliComelex(ComplexNum1,ComplexNum2);

    printf("result of addition complex: ");
    display(Sumresult);
    printf("\n");
    printf("result of Multiplicaiton complex: ");
    display(Productresult);
    
}