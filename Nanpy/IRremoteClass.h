#ifndef IRREMOTE_CLASS
#define IRREMOTE_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

class IRsend;
class IRrecv;

namespace nanpy {
    class IRsendClass: public ObjectsManager<IRsend> {

        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();

    };
    class IRrecvClass: public ObjectsManager<IRrecv> {

        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();

    };
}
#endif
