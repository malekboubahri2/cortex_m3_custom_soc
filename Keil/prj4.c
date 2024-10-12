typedef unsigned int uint32_t;
#define CPU_ID_REG_ADDR (uint32_t *) (0xE000ED00)
#define GPIO_1 *((uint32_t *) (0x20000ff0))
int main ()
{
  int kk[5]={0xa,0xb,0xc,0xd,0xe};
  int jj;
    uint32_t cpu_id_var;
    const uint32_t cpu_id_val = 0x410FC240;
   
   
    for(jj=0;jj<kk[0];jj++)
    {
        __asm("NOP");
        cpu_id_var = *(CPU_ID_REG_ADDR);
        if(cpu_id_var == cpu_id_val)
        {
            GPIO_1 = 0x1;
        }
        else
        {
            GPIO_1 = 0x2;
        }
        __asm("NOP");
    }
    while(1);
}