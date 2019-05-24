#include <stdio.h>
#include "windows.h"
#include <vim.h>

int main(int argc, char* argv) {
    /* AttachConsole(-1); */
    /* MessageBoxA( */
    /*         NULL, */
    /*         "HELLO", */
    /*         "WORLD", */
    /*         0); */
    mparm_T	params;
    vim_memset(&params, 0, sizeof(params));
    params.argc = argc;
    params.argv = argv;
    params.want_full_screen = TRUE;
    params.window_count = -1;

    mch_early_init();
    common_init(&params);
    printf("Hello\n");
    buf_T* buffer = buflist_new("C:/test.txt", NULL, 1, 0);
    set_curbuf(buffer, 0);
    ins_bytes("HELLO");
	close_buffer(NULL, curbuf, 0, FALSE);

    edit_putchar('D', 0);

    char* edit = get_last_insert();
    printf("LAST EDIT: %s \n", edit);

    char *line = ml_get(0);
    printf("LINE: %s\n", line);

    printf("Done!\n");

    return -1;
}
