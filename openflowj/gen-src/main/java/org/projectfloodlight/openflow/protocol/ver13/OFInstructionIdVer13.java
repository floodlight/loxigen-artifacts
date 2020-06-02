// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_virtual_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver13;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import io.netty.buffer.ByteBuf;

abstract class OFInstructionIdVer13 {
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int MINIMUM_LENGTH = 4;


    public final static OFInstructionIdVer13.Reader READER = new Reader();

    static class Reader implements OFMessageReader<OFInstructionId> {
        @Override
        public OFInstructionId readFrom(ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < MINIMUM_LENGTH)
                return null;
            int start = bb.readerIndex();
            short type = bb.readShort();
            bb.readerIndex(start);
            switch(type) {
               case (short) 0x4:
                   // discriminator value OFInstructionType.APPLY_ACTIONS=4 for class OFInstructionIdApplyActionsVer13
                   return OFInstructionIdApplyActionsVer13.READER.readFrom(bb);
               case (short) 0x5:
                   // discriminator value OFInstructionType.CLEAR_ACTIONS=5 for class OFInstructionIdClearActionsVer13
                   return OFInstructionIdClearActionsVer13.READER.readFrom(bb);
               case (short) 0xffff:
                   // discriminator value OFInstructionType.EXPERIMENTER=65535 for class OFInstructionIdExperimenterVer13
                   return OFInstructionIdExperimenterVer13.READER.readFrom(bb);
               case (short) 0x1:
                   // discriminator value OFInstructionType.GOTO_TABLE=1 for class OFInstructionIdGotoTableVer13
                   return OFInstructionIdGotoTableVer13.READER.readFrom(bb);
               case (short) 0x6:
                   // discriminator value OFInstructionType.METER=6 for class OFInstructionIdMeterVer13
                   return OFInstructionIdMeterVer13.READER.readFrom(bb);
               case (short) 0x3:
                   // discriminator value OFInstructionType.WRITE_ACTIONS=3 for class OFInstructionIdWriteActionsVer13
                   return OFInstructionIdWriteActionsVer13.READER.readFrom(bb);
               case (short) 0x2:
                   // discriminator value OFInstructionType.WRITE_METADATA=2 for class OFInstructionIdWriteMetadataVer13
                   return OFInstructionIdWriteMetadataVer13.READER.readFrom(bb);
               default:
                   throw new OFParseError("Unknown value for discriminator type of class OFInstructionIdVer13: " + type);
            }
        }
    }
}
