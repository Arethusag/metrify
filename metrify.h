#ifndef METRIFY_H
#define METRIFY_H
#define METRIFY_SUCCESS 0
#define METRIFY_FAILURE -1

int Metrify_Set_Seed(unsigned int seed);
int Metrify_Get_Seconds_Since_Epoch(unsigned int* out_seconds);
int Metrify_Set_Time_Based_Seed(void);
int Metrify_Random_Number(unsigned int limit, unsigned int* out_number);
int Metrify_Random_Number_From_Range(unsigned int start, unsigned int end, unsigned int* out_number);
#endif
