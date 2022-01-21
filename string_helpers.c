#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "string_helpers.h"

#define LOG_ERR(x) printf("ERROR: " x)
#define LOG_WRN(x) printf("WARNING: " x)

int str_replace(const char *input_str,
                const char *find_substr,
                const char *replacement_substr,
                char *output_str,
                const size_t output_len)
{
    size_t used_buf_len              = 0;
    const char *str_start_to_process = input_str;
    const char *substr_pos;

    const char *input_str_end    = input_str + strlen(input_str);
    const size_t replacement_len = strlen(replacement_substr);
    const size_t find_len        = strlen(find_substr);
    size_t len_to_cpy;

    if (strlen(input_str) >= output_len) {
        LOG_ERR("input_str is larger than output_len");
        return -1;
    }
    if (strlen(input_str) == 0) {
        LOG_WRN("input_str is empty");
        output_str[0] = '\0';
        return 0;
    }
    if (strlen(find_substr) == 0) {
        LOG_WRN("Searching for empty string, no need to replace anything");
        strncpy(output_str, input_str, output_len);
        return snprintf(output_str, output_len, "%s", input_str);
    }

    while (true) {
        substr_pos = strstr(str_start_to_process, find_substr);
        if (!substr_pos) {
            strncpy(&output_str[used_buf_len], str_start_to_process, output_len - used_buf_len);
            break;
        }

        /* Copy up until substr */
        len_to_cpy = substr_pos - str_start_to_process;
        strncpy(&output_str[used_buf_len], str_start_to_process, len_to_cpy);
        used_buf_len += len_to_cpy;
        /* Copy replacement instead of substr */
        strncpy(&output_str[used_buf_len], replacement_substr, replacement_len);
        used_buf_len += replacement_len;

        /* Move up marker to after found substr */
        str_start_to_process = str_start_to_process + len_to_cpy + find_len;
        if (str_start_to_process > input_str_end) {
            LOG_ERR("Something went wrong, copied too much!?");
            return -1;
        }
        if (str_start_to_process == input_str_end) {
            /* Got to the end, so stop, make sure we terminate the string */
            output_str[used_buf_len] = '\0';
            break;
        }
    }

    return strlen(output_str);
}

#undef LOG_ERR
#undef LOG_WRN
