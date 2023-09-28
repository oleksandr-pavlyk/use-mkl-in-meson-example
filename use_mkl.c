#include "mkl.h"
#include "stdio.h"

int main(void) {
    char buf[256];
    int buf_sz = 256;

    mkl_get_version_string(buf, buf_sz);
    printf("%s\n", buf);
    printf("\n");

    double v1[8] = {1., 0., 1., 0., 1., 0., 1., 0.};
    double v2[8] = {1., -1., 1., -1, 1., -1., 1., -1.};

    double res = cblas_ddot(8, v1, 1, v2, 1);

    printf("Computed dot product value: %e\n", res);
    printf("Expected dot product value: %e\n", 4.0);
  
    return 0;
}
