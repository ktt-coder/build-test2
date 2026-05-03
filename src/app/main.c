#include <stdio.h>
#include <stdlib.h>

void null_deref(int flag) {
    char *p = NULL;
    if (flag) {
        // p に値をセットする分岐がないため、flag==0 のときに NULL を参照する
        p = "hello";
    }
    // ここで p を参照 -> Null dereference を報告される可能性が高い
    printf("%c\n", p[0]);
}

void memory_leak(int cond) {
    char *buf = malloc(128);
    if (!buf) return;
    if (cond) {
        // 条件分岐で早期 return -> buf が解放されないパスがある
        return;
    }
    // 正常パスでは free するが、上の分岐で漏れる
    free(buf);
}

void use_after_free(void) {
    char *p = malloc(16);
    if (!p) return;
    p[0] = 'A';
    free(p);
    // free 後にアクセス -> Use-after-free を検出されやすい
    printf("%c\n", p[0]);
}

void buffer_overflow(void) {
    char buf[8];
    // 長い文字列をコピー -> stack buffer overflow 警告が出ることがある
    strcpy(buf, "this-is-longer-than-8");
}

void use_uninit(int cond) {
    int x; // 初期化されていない
    if (cond) {
        x = 1;
    }
    // cond == 0 のとき x は初期化されていないまま使用される可能性がある
    if (x == 1) {
        printf("x is 1\n");
    }
}

int main(void) {
    null_deref(0);
    memory_leak(1);
    use_after_free();
    buffer_overflow();
    use_uninit(0);
    int i;
    char *p = malloc(1);
    return 0;
}
