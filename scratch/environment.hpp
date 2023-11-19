#include <cstdarg>
#include <cstdint>
#include <cstddef>

#include "arch/primitives.h"

namespace kernel 
{
    namespace events
    {
        class environment
        {
        public:
            environment();
            bool attach_vector(uint8_t irq, void (*handler)(struct interrupt_frame *));
            bool attach_vector(uint8_t irq, void (*handler)(struct interrupt_frame *, uword_t));

        private:
            struct gdt_ptr   gdt;
            struct gdt_entry gdt_entries[6];
            struct idt_ptr   idt;
            struct idt_entry idt_entries[256];

            void stub_vector    (struct interrupt_frame *frm);
            void stub_exception (struct interrupt_frame *frm, uword_t err);
            void configure_gdt  (void);
            void configure_idt  (void);
            void disable_8259s  (void);
            void configure_lapic(void);
        }
    }
}