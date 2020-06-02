// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver15;

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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFInstructionIdBsnSpanDestinationVer15 implements OFInstructionIdBsnSpanDestination {
    private static final Logger logger = LoggerFactory.getLogger(OFInstructionIdBsnSpanDestinationVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 12;


    // OF message fields
//
    // Immutable default instance
    final static OFInstructionIdBsnSpanDestinationVer15 DEFAULT = new OFInstructionIdBsnSpanDestinationVer15(

    );

    final static OFInstructionIdBsnSpanDestinationVer15 INSTANCE = new OFInstructionIdBsnSpanDestinationVer15();
    // private empty constructor - use shared instance!
    private OFInstructionIdBsnSpanDestinationVer15() {
    }

    // Accessors for OF message fields
    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public long getSubtype() {
        return 0xaL;
    }

    @Override
    public OFInstructionType getType() {
        return OFInstructionType.EXPERIMENTER;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    // no data members - do not support builder
    public OFInstructionIdBsnSpanDestination.Builder createBuilder() {
        throw new UnsupportedOperationException("OFInstructionIdBsnSpanDestinationVer15 has no mutable properties -- builder unneeded");
    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFInstructionIdBsnSpanDestination> {
        @Override
        public OFInstructionIdBsnSpanDestination readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 65535
            short type = bb.readShort();
            if(type != (short) 0xffff)
                throw new OFParseError("Wrong type: Expected=OFInstructionType.EXPERIMENTER(65535), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 12)
                throw new OFParseError("Wrong length: Expected=12(12), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            // fixed value property experimenter == 0x5c16c7L
            int experimenter = bb.readInt();
            if(experimenter != 0x5c16c7)
                throw new OFParseError("Wrong experimenter: Expected=0x5c16c7L(0x5c16c7L), got="+experimenter);
            // fixed value property subtype == 0xaL
            int subtype = bb.readInt();
            if(subtype != 0xa)
                throw new OFParseError("Wrong subtype: Expected=0xaL(0xaL), got="+subtype);

            if(logger.isTraceEnabled())
                logger.trace("readFrom - returning shared instance={}", INSTANCE);
            return INSTANCE;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFInstructionIdBsnSpanDestinationVer15Funnel FUNNEL = new OFInstructionIdBsnSpanDestinationVer15Funnel();
    static class OFInstructionIdBsnSpanDestinationVer15Funnel implements Funnel<OFInstructionIdBsnSpanDestinationVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFInstructionIdBsnSpanDestinationVer15 message, PrimitiveSink sink) {
            // fixed value property type = 65535
            sink.putShort((short) 0xffff);
            // fixed value property length = 12
            sink.putShort((short) 0xc);
            // fixed value property experimenter = 0x5c16c7L
            sink.putInt(0x5c16c7);
            // fixed value property subtype = 0xaL
            sink.putInt(0xa);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFInstructionIdBsnSpanDestinationVer15> {
        @Override
        public void write(ByteBuf bb, OFInstructionIdBsnSpanDestinationVer15 message) {
            // fixed value property type = 65535
            bb.writeShort((short) 0xffff);
            // fixed value property length = 12
            bb.writeShort((short) 0xc);
            // fixed value property experimenter = 0x5c16c7L
            bb.writeInt(0x5c16c7);
            // fixed value property subtype = 0xaL
            bb.writeInt(0xa);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFInstructionIdBsnSpanDestinationVer15(");
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = 1;

        return result;
    }

}
