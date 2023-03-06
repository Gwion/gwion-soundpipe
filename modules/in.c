#include <stdlib.h>
#include "soundpipe.h"

int sp_in_create(sp_in **p)
{
    *p = malloc(sizeof(sp_in));
    return SP_OK;
}

int sp_in_destroy(sp_in **p)
{
    sp_in *pp = *p;
    fclose(pp->fp);
    free(*p);
    return SP_OK;
}

int sp_in_init(sp_data *sp, sp_in *p)
{
    p->fp = stdin; 
    return SP_OK;
}

int sp_in_compute(sp_data *sp, sp_in *p, SPFLOAT *in, SPFLOAT *out)
{
    *out = 0;
    if(fread(out, sizeof(SPFLOAT), 1, p->fp) < 1)
      return SP_NOT_OK;
    return SP_OK;
}
