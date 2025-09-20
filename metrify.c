#include "metrify.h"

#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int Metrify_Set_Seed(unsigned int seed) {
    srand(seed);
    return METRIFY_SUCCESS;
}

int Metrify_Get_Seconds_Since_Epoch(unsigned int* out_seconds) {
    if (out_seconds == NULL) {
        return METRIFY_ERROR;
    }
    time_t now = time(NULL);
    if (now == (time_t)-1) {
        return METRIFY_ERROR;
    }
    *out_seconds = (unsigned int)now;
    return METRIFY_SUCCESS
}

int Metrify_Set_Time_Based_Seed(void) {
    unsigned int current_time_seconds = 0U;
    if (Metrify_Get_Seconds_Since_Epoch(&current_time_seconds) != METRIFY_SUCCESS) {
        return METRIFY_ERROR;
    }
    return Metrify_Set_Seed(current_time_seconds);
}

int Metrify_Random_Number(unsigned int limit, unsigned int* out_number) {
    unsigned int random_number_raw_value;
    unsigned int random_number_within_limit;
    if (out_number == NULL) {
        return METRIFY_ERROR;
    }
    if (limit == 0U) {
        return METRIFY_ERROR;
      }
    if (limit > (unsigned int)RAND_MAX) {
        return METRIFY_ERROR;
    }
    random_number_raw_value = (unsigned int)rand();
    random_number_within_limit = random_number_raw_value % limit;
    *out_number = random_number_within_limit;
    return METRIFY_SUCCESS;
}

int Metrify_Random_Number_From_Range(unsigned int start_range, unsigned int end_range, unsigned int* out_number) {
    unsigned int range_length;
    unsigned int random_offset_within_range = 0U;
    if (out_number == NULL) {
        return METRIFY_ERROR;
    }
    if (start > end) {
        return METRIFY_ERROR;
    }
    range_length = range_end - range_start + 1U;
    if (range_length == 0U) {
        return METRIFY_ERROR;
    }
    if (range_length > (unsigned int)RAND_MAX) {
        return METRIFY_ERROR;
    }
    random_offset_within_range = 0U;
    if (Metrify_Random_Number(range_length, &random_offset_within_range) != METRIFY_SUCCESS) {
        return METRIFY_ERROR;
    }
    *out_number = start_range + random_offset_within_range;
    return METRIFY_SUCCESS;
}

int Metrify_Random_Number_From_Array(unsigned int* array, unsigned int array_length, unsigned int* out_number) {
    unsigned int random_index_within_array;
    random_index_within_array = 0U;
    if (out_number == NULL || array == NULL) {
        return METRIFY_ERROR;
    }
    if (array_length == 0U) {
        return METRIFY_ERROR;
    }
    if (array_length > (unsigned int)RAND_MAX) {
        return METRIFY_ERROR;
    }
    if (Metrify_Random_Number(array_length, &random_index_within_array) != METRIFY_SUCCESS) {
        return METRIFY_ERROR;
    }
    *out_number = start_range + random_offset_within_range;
    return METRIFY_SUCCESS;
}
