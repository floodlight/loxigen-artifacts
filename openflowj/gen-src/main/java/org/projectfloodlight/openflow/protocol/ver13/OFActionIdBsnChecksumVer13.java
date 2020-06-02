// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFActionIdBsnChecksumVer13 implements OFActionIdBsnChecksum {
    private static final Logger logger = LoggerFactory.getLogger(OFActionIdBsnChecksumVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int LENGTH = 12;


    // OF message fields
//
    // Immutable default instance
    final static OFActionIdBsnChecksumVer13 DEFAULT = new OFActionIdBsnChecksumVer13(

    );

    final static OFActionIdBsnChecksumVer13 INSTANCE = new OFActionIdBsnChecksumVer13();
    // private empty constructor - use shared instance!
    private OFActionIdBsnChecksumVer13() {
    }

    // Accessors for OF message fields
    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public long getSubtype() {
        return 0x4L;
    }

    @Override
    public OFActionType getType() {
        return OFActionType.EXPERIMENTER;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



    // no data members - do not support builder
    public OFActionIdBsnChecksum.Builder createBuilder() {
        throw new UnsupportedOperationException("OFActionIdBsnChecksumVer13 has no mutable properties -- builder unneeded");
    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFActionIdBsnChecksum> {
        @Override
        public OFActionIdBsnChecksum readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 65535
            short type = bb.readShort();
            if(type != (short) 0xffff)
                throw new OFParseError("Wrong type: Expected=OFActionType.EXPERIMENTER(65535), got="+type);
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
            // fixed value property subtype == 0x4L
            int subtype = bb.readInt();
            if(subtype != 0x4)
                throw new OFParseError("Wrong subtype: Expected=0x4L(0x4L), got="+subtype);

            if(logger.isTraceEnabled())
                logger.trace("readFrom - returning shared instance={}", INSTANCE);
            return INSTANCE;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFActionIdBsnChecksumVer13Funnel FUNNEL = new OFActionIdBsnChecksumVer13Funnel();
    static class OFActionIdBsnChecksumVer13Funnel implements Funnel<OFActionIdBsnChecksumVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFActionIdBsnChecksumVer13 message, PrimitiveSink sink) {
            // fixed value property type = 65535
            sink.putShort((short) 0xffff);
            // fixed value property length = 12
            sink.putShort((short) 0xc);
            // fixed value property experimenter = 0x5c16c7L
            sink.putInt(0x5c16c7);
            // fixed value property subtype = 0x4L
            sink.putInt(0x4);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFActionIdBsnChecksumVer13> {
        @Override
        public void write(ByteBuf bb, OFActionIdBsnChecksumVer13 message) {
            // fixed value property type = 65535
            bb.writeShort((short) 0xffff);
            // fixed value property length = 12
            bb.writeShort((short) 0xc);
            // fixed value property experimenter = 0x5c16c7L
            bb.writeInt(0x5c16c7);
            // fixed value property subtype = 0x4L
            bb.writeInt(0x4);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFActionIdBsnChecksumVer13(");
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
