
#ifndef _STRING_HELPERS_H_
#define _STRING_HELPERS_H_

#include <stdio.h>

/* @brief Replace all instances of @param find_substr in @param input_str with
 *        @param replacement_substr.
 * 
 * @note The user needs to make sure the @param output_str can fit the string
 *       with all replacements made.
 *
 * @param input_str The string to copy and find-replace in
 * @param find_substr The substring to find
 * @param replacement_substr The replacement substring
 * @param output_str The buffer where to write the new string to
 * @param output_len The length of the output buffer
 *
 * @returns the length of the string written to @param output_str, or -1 if an
 *          error occurred.
 */
int str_replace(const char *input_str,
                const char *find_substr,
                const char *replacement_substr,
                char *output_str,
                const size_t output_len);

#endif /* _STRING_HELPERS_H_ */
