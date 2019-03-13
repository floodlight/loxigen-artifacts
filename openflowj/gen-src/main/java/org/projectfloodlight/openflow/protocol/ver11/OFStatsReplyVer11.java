// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_virtual_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver11;

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

abstract class OFStatsReplyVer11 {
    // version: 1.1
    final static byte WIRE_VERSION = 2;
    final static int MINIMUM_LENGTH = 16;


    public final static OFStatsReplyVer11.Reader READER = new Reader();

    static class Reader extends AbstractOFMessageReader<OFStatsReply> {
        @Override
        public OFStatsReply readFrom(OFMessageReaderContext context, ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < MINIMUM_LENGTH)
                return null;
            int start = bb.readerIndex();
            // fixed value property version == 2
            byte version = bb.readByte();
            if(version != (byte) 0x2)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_11(2), got="+version);
            // fixed value property type == 19
            byte type = bb.readByte();
            if(type != (byte) 0x13)
                throw new OFParseError("Wrong type: Expected=OFType.STATS_REPLY(19), got="+type);
            int length = U16.f(bb.readShort());
            if(length < MINIMUM_LENGTH)
                throw new OFParseError("Wrong length: Expected to be >= " + MINIMUM_LENGTH + ", was: " + length);
            if( ( bb.readableBytes() + (bb.readerIndex() - start)) < length ) {
                // message not yet fully read
                bb.readerIndex(start);
                return null;
            }
            U32.f(bb.readInt());
            short statsType = bb.readShort();
            switch(statsType) {
               case (short) 0x2:
                   bb.readerIndex(start);
                   // discriminator value OFStatsType.AGGREGATE=2 for class OFAggregateStatsReplyVer11
                   return OFAggregateStatsReplyVer11.READER.readFrom(context, bb);
               case (short) 0xffff:
                   bb.readerIndex(start);
                   // discriminator value OFStatsType.EXPERIMENTER=65535 for class OFExperimenterStatsReplyVer11
                   return OFExperimenterStatsReplyVer11.READER.readFrom(context, bb);
               case (short) 0x0:
                   bb.readerIndex(start);
                   // discriminator value OFStatsType.DESC=0 for class OFDescStatsReplyVer11
                   return OFDescStatsReplyVer11.READER.readFrom(context, bb);
               case (short) 0x1:
                   bb.readerIndex(start);
                   // discriminator value OFStatsType.FLOW=1 for class OFFlowStatsReplyVer11
                   return OFFlowStatsReplyVer11.READER.readFrom(context, bb);
               case (short) 0x4:
                   bb.readerIndex(start);
                   // discriminator value OFStatsType.PORT=4 for class OFPortStatsReplyVer11
                   return OFPortStatsReplyVer11.READER.readFrom(context, bb);
               case (short) 0x5:
                   bb.readerIndex(start);
                   // discriminator value OFStatsType.QUEUE=5 for class OFQueueStatsReplyVer11
                   return OFQueueStatsReplyVer11.READER.readFrom(context, bb);
               case (short) 0x3:
                   bb.readerIndex(start);
                   // discriminator value OFStatsType.TABLE=3 for class OFTableStatsReplyVer11
                   return OFTableStatsReplyVer11.READER.readFrom(context, bb);
               case (short) 0x7:
                   bb.readerIndex(start);
                   // discriminator value OFStatsType.GROUP_DESC=7 for class OFGroupDescStatsReplyVer11
                   return OFGroupDescStatsReplyVer11.READER.readFrom(context, bb);
               case (short) 0x6:
                   bb.readerIndex(start);
                   // discriminator value OFStatsType.GROUP=6 for class OFGroupStatsReplyVer11
                   return OFGroupStatsReplyVer11.READER.readFrom(context, bb);
               default:
                   context.getUnparsedHandler().unparsedMessage(OFStatsReplyVer11.class, "statsType", statsType);
            }
            OFStatsReplyFlagsSerializerVer11.readFrom(bb);
            // pad: 4 bytes
            bb.skipBytes(4);
            // will only reach here if the discriminator turns up nothing.
            bb.skipBytes(length - (bb.readerIndex() - start));
            return null;
        }
    }
}
