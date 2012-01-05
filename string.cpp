#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <utils/String16.h>
#include <ctype.h>

using namespace android;

#define FILENAME    "/data/a.txt"

void save_file(String16 &str)
{
    FILE *fp = fopen(FILENAME, "w");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    int ret = fwrite(str.string(), 1, str.size()*sizeof(char16_t), fp);

    printf("Write %d bytes to file\n", ret);

    fclose(fp);
}

String16 load_file()
{
    struct stat st;
    stat(FILENAME, &st);

    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    char16_t *buf = new char16_t[st.st_size+1];

    int ret = fread(buf, 1, st.st_size, fp);
    buf[st.st_size] = 0;

    printf("Read %d bytes from file\n", ret);

    delete [] buf;
    fclose(fp);

    return String16(buf);
}

int main()
{
    String16 abc("Hello");
    char buf[128];

    for (int i = 0; i < abc.size(); ++i) {
        buf[i] = abc.string()[i];
    }

    buf[abc.size()] = '\0';

    printf("%s\n", buf);

    return 0;
}
