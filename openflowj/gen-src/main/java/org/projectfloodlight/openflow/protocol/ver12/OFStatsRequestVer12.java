// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_virtual_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver12;

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

abstract class OFStatsRequestVer12 {
    // version: 1.2
    final static byte WIRE_VERSION = 3;
    final static int MINIMUM_LENGTH = 16;


    public final static OFStatsRequestVer12.Reader READER = new Reader();

    static class Reader implements OFMessageReader<OFStatsRequest<?>> {
        @Override
        public OFStatsRequest<?> readFrom(ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < MINIMUM_LENGTH)
                return null;
            int start = bb.readerIndex();
            // fixed value property version == 3
            byte version = bb.readByte();
            if(version != (byte) 0x3)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_12(3), got="+version);
            // fixed value property type == 18
            byte type = bb.readByte();
            if(type != (byte) 0x12)
                throw new OFParseError("Wrong type: Expected=OFType.STATS_REQUEST(18), got="+type);
            int length = U16.f(bb.readShort());
            if(length < MINIMUM_LENGTH)
                throw new OFParseError("Wrong length: Expected to be >= " + MINIMUM_LENGTH + ", was: " + length);
            U32.f(bb.readInt());
            short statsType = bb.readShort();
            bb.readerIndex(start);
            switch(statsType) {
               case (short) 0x2:
                   // discriminator value OFStatsType.AGGREGATE=2 for class OFAggregateStatsRequestVer12
                   return OFAggregateStatsRequestVer12.READER.readFrom(bb);
               case (short) 0x0:
                   // discriminator value OFStatsType.DESC=0 for class OFDescStatsRequestVer12
                   return OFDescStatsRequestVer12.READER.readFrom(bb);
               case (short) 0xffff:
                   // discriminator value OFStatsType.EXPERIMENTER=65535 for class OFExperimenterStatsRequestVer12
                   return OFExperimenterStatsRequestVer12.READER.readFrom(bb);
               case (short) 0x1:
                   // discriminator value OFStatsType.FLOW=1 for class OFFlowStatsRequestVer12
                   return OFFlowStatsRequestVer12.READER.readFrom(bb);
               case (short) 0x7:
                   // discriminator value OFStatsType.GROUP_DESC=7 for class OFGroupDescStatsRequestVer12
                   return OFGroupDescStatsRequestVer12.READER.readFrom(bb);
               case (short) 0x8:
                   // discriminator value OFStatsType.GROUP_FEATURES=8 for class OFGroupFeaturesStatsRequestVer12
                   return OFGroupFeaturesStatsRequestVer12.READER.readFrom(bb);
               case (short) 0x6:
                   // discriminator value OFStatsType.GROUP=6 for class OFGroupStatsRequestVer12
                   return OFGroupStatsRequestVer12.READER.readFrom(bb);
               case (short) 0x4:
                   // discriminator value OFStatsType.PORT=4 for class OFPortStatsRequestVer12
                   return OFPortStatsRequestVer12.READER.readFrom(bb);
               case (short) 0x5:
                   // discriminator value OFStatsType.QUEUE=5 for class OFQueueStatsRequestVer12
                   return OFQueueStatsRequestVer12.READER.readFrom(bb);
               case (short) 0x3:
                   // discriminator value OFStatsType.TABLE=3 for class OFTableStatsRequestVer12
                   return OFTableStatsRequestVer12.READER.readFrom(bb);
               default:
                   throw new OFParseError("Unknown value for discriminator statsType of class OFStatsRequestVer12: " + statsType);
            }
        }
    }
}
