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
    init_normal_cmds();
    oparg_T	oa;	/* operator arguments */


    buf_T* buffer = buflist_new("C:/test.txt", NULL, 1, 0);
    set_curbuf(buffer, 0);
    linenr_T	lnum;
	    lnum = curwin->w_cursor.lnum;
    printf("lnum: %d", lnum);
    
    char * keys_esc = vim_strsave_escape_csi("ggGddowxyz\033I123\015\033");

    ins_typebuf(keys_esc, REMAP_YES, 0, FALSE, FALSE);
		      printf("TYPEBUF: %s\n", typebuf.tb_buf);
    printf("\nInserted\n", edit);
    exec_normal(TRUE, FALSE, FALSE);
    printf ("\nEXECUTED\n");
    /* ins_bytes("HELLO"); */


    /* edit_putchar('D', 0); */
    char * keys2= vim_strsave_escape_csi(":help tutor\015");
    ins_typebuf(keys2, REMAP_YES, 0, FALSE, FALSE);
    /* ins_typebuf(keys2, REMAP_YES, 0, FALSE, FALSE); */
    printf("\nInserted\n", edit);

    win_setheight(100);
    win_setwidth(100);

    exec_normal(TRUE, FALSE, FALSE);

    char* edit = get_last_insert();
    printf("LAST EDIT: %s \n", edit);

	    lnum = curwin->w_cursor.lnum;
        printf("lnum: %d", lnum);

    char *line = ml_get(3);
    printf("LINE: %s\n", line);

    printf("Done!\n");

    return -1;
}
