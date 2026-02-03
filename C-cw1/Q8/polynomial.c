#include "q8.h"


Polynomial* createTerm(float coef, int pow) {
    Polynomial* term = (Polynomial*)malloc(sizeof(Polynomial));
    term->coef = coef;
    term->pow = pow;
    term->nex = NULL;
    return term;
}
Polynomial* readPoly(void){
    Polynomial* head = NULL;
    Polynomial* pointer = NULL;
    int n, pow;
    float coef;

    printf("Input terms: ");
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        
        scanf("%f %d", &coef,&pow);
        
        if (!head){
            
            head = createTerm(coef,pow);
            pointer = head;
     
        }else{
            pointer->nex = createTerm(coef,pow);
            pointer = pointer->nex;
        }
    }
    return head;

}

Polynomial* add(Polynomial* poly1, Polynomial* poly2){
    Polynomial *new_poly=NULL;
    Polynomial *p = NULL;
    
    float coef;
    int pow;
    while (poly1 || poly2){
    if (poly1 && (!poly2 ||poly1->pow>poly2->pow)){
        coef = poly1->coef;
        pow = poly1->pow;
        poly1 = poly1->nex;  }
    else if (poly2 && (!poly1||poly1->pow<poly2->pow)){
        coef = poly2->coef;
        pow = poly2->pow;
        poly2 = poly2->nex;  }
    else{
        coef = poly1->coef+poly2->coef;
        pow = poly1->pow;
        poly1 = poly1->nex;
        poly2 = poly2->nex;
    }
    if (!new_poly && coef){
        new_poly = createTerm(coef,pow);
        p = new_poly;
    }else if (coef){
        p->nex=createTerm(coef,pow);
        p = p->nex;
    }}
    return new_poly;
}

Polynomial* subtract(Polynomial* poly1, Polynomial* poly2){
    Polynomial *new_poly=NULL;
    Polynomial *p = NULL;
    
    float coef;
    int pow;
    while (poly1 || poly2){
    if (poly1 && (!poly2||poly1->pow>poly2->pow)){
        coef = poly1->coef;
        pow = poly1->pow;
        poly1 = poly1->nex;  }
    else if(poly2 && (!poly1||poly1->pow<poly2->pow)){
        coef = -poly2->coef;
        pow = poly2->pow;
        poly2 = poly2->nex;
    }
    else{
        coef = poly1->coef-poly2->coef;
        pow = poly1->pow;
        poly1 = poly1->nex;
        poly2 = poly2->nex;
    }
    if (!new_poly && coef){
        new_poly = createTerm(coef,pow);
        p = new_poly;
    }else if (coef){
        p->nex=createTerm(coef,pow);
        p = p->nex;
    }}
    return new_poly;
}

Polynomial* multiply(Polynomial* poly1, Polynomial* poly2){
    if (!poly2) return NULL;
    Polynomial *p1 = poly1;
    Polynomial *new_poly = createTerm(poly2->coef*poly1->coef,poly1->pow+poly2->pow);
    Polynomial *p = new_poly;
    p1 = p1->nex;
    float coef;
    int pow;
    while(p1){
        p->nex = createTerm(poly2->coef*p1->coef,p1->pow+poly2->pow);
        p = p->nex;
        p1 = p1->nex;
    }
    poly2 = poly2->nex;
    return add(multiply(poly1,poly2),new_poly);
}

float getValue(Polynomial*p, float x){
    if (!p) return 0.0;       
    Polynomial *pointer = p->nex;
    float res=p->coef;
    for (int i=p->pow;i>=1;i--)
    {
    if (pointer && pointer->pow==i-1){
        res = res*x+pointer->coef;
        pointer = pointer->nex;
    }
    else{
        res = res*x;
    }}  
    return res;
}

void printPoly(Polynomial* p){
    printf("%.2fx^%d", p->coef,p->pow);
    p = p->nex;
    while (p)
    {
        if (p->pow==0){
            if (p->coef<0)printf("%.2f",p->coef);
            else printf("+%.2f",p->coef);
            break;}
        if (p->coef<0)printf("%.2fx^%d",p->coef,p->pow);
        else printf("+%.2fx^%d",p->coef,p->pow);
        
        p = p->nex;
    }
    printf("\n");
}