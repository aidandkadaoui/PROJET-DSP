MEMORY
{
/*Internal RAM: 256KB starting at 0x00000000 */
    IRAM     o = 0x00000000  l = 0x00040000
}
SECTIONS
{
    .text          >  IRAM	/* Executable code */
    .stack         >  IRAM	/* Software stack */
    .bss           >  IRAM	/* Global/Static variables */
    .cio           >  IRAM	/* C I/0 (printf/fopen) */
    .const         >  IRAM	/* Constant data (the 'image' array) */
    .cinit         >  IRAM	/* Initialization tables */
    .data          >  IRAM	/* Initialized data */
    .switch        >  IRAM	/* Jump tables for switch statements */
    .sysmem        >  IRAM	/* Memory for malloc/free */
    .far           >  IRAM	/* Global variables declared far */

/* Our specific image buffers for the chromosome analysis */
    .img_data	      >  IRAM
