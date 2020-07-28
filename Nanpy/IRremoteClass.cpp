#include "cfg_all.h"
#include <Arduino.h>
#include <IRremote.h>
#include "IRremoteClass.h"
#include <stdlib.h>

const char* nanpy::IRsendClass::get_firmware_id()
{
    return "IRsend";
}

void nanpy::IRsendClass::elaborate( nanpy::MethodDescriptor* m ) {
        ObjectsManager<IRsend>::elaborate(m);

        if (strcmp(m->getName(),"new") == 0) {
            v.insert(new IRsend());
            m->returns(v.getLastIndex());
        }

        if (strcmp(m->getName(), "sendRC5") == 0) {
            v[m->getObjectId()]->sendRC5(m->getInt(0), m->getInt(1));
            m->returns(0);
        }

        if (strcmp(m->getName(), "sendRC6") == 0) {
            v[m->getObjectId()]->sendRC6(m->getInt(0), m->getInt(1));
            m->returns(0);
        }
};


const char* nanpy::IRrecvClass::get_firmware_id()
{
    return "IRrecv";
}

void nanpy::IRrecvClass::elaborate( nanpy::MethodDescriptor* m ) {
        ObjectsManager<IRrecv>::elaborate(m);

        if (strcmp(m->getName(),"new") == 0) {
            v.insert(new IRrecv(m->getInt(0)));
            m->returns(v.getLastIndex());
        }

        if (strcmp(m->getName(), "enableIRIn") == 0) {
            v[m->getObjectId()]->enableIRIn();
            m->returns(0);
        }

        if (strcmp(m->getName(), "disableIRIn") == 0) {
            v[m->getObjectId()]->disableIRIn();
            m->returns(0);
        }

        if (strcmp(m->getName(), "isIdle") == 0) {
            m->returns(v[m->getObjectId()]->isIdle());
        }

        if (strcmp(m->getName(), "resume") == 0) {
            v[m->getObjectId()]->resume();
            m->returns(0);
        }

        if (strcmp(m->getName(), "decode") == 0) {
            decode_results results;
            if (v[m->getObjectId()]->decode(&results)) {
                String value = String(results.value, HEX);
                m->returns(value);
            }
            else {
                m->returns(0);
            }  
        }
};
