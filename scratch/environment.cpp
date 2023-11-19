#include "environment.hpp"

kernel::events::environment::environment()
{

}

bool kernel::events::environment::attach_vector(uint8_t irq, void (*handler)(struct interrupt_frame *frm))
{

}

bool kernel::events::environment::attach_vector(uint8_t irq, void (*handler)(struct interrupt_frame *frm, uword_t err))
{
    
}