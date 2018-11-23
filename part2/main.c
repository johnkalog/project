//#define __STDC_FORMAT_MACROS
#include "Full_Relation.h"

int main(int argc,char *argv[]) {

    if(argc!=7){
        printf("Need 6 arguments\n");
        exit(1);
    }
    unsigned int num_lines;
    full_relation *relations_array = NULL;
    //tuple **tuple_arrays;

    relations_array=full_relation_creation(argv[1],&num_lines);

    //print_relation(relations_array[0]);

    //char str[50] = "0 2 4|0.1=1.2&1.0=2.1&0.1>3000|0.0 1.1";
    int relAindex=atoi(argv[3]),relBindex=atoi(argv[4]),relAcol=atoi(argv[5]),relBcol=atoi(argv[6]);

    sql_reader(argv[2]);

    result *Result=RHJcaller(relations_array,relAindex,relBindex,relAcol,relBcol);
    free_structs(relations_array,num_lines);

    printf("Press Enter\n");
    getchar();
    sleep(1);
    printf("Done\n");
    result_print(Result);

    result_free(Result);
    return 0;
}
