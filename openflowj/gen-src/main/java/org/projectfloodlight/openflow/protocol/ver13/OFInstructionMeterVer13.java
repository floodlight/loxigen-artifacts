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
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFInstructionMeterVer13 implements OFInstructionMeter {
    private static final Logger logger = LoggerFactory.getLogger(OFInstructionMeterVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int LENGTH = 8;

        private final static long DEFAULT_METER_ID = 0x0L;

    // OF message fields
    private final long meterId;
//
    // Immutable default instance
    final static OFInstructionMeterVer13 DEFAULT = new OFInstructionMeterVer13(
        DEFAULT_METER_ID
    );

    // package private constructor - used by readers, builders, and factory
    OFInstructionMeterVer13(long meterId) {
        this.meterId = meterId;
    }

    // Accessors for OF message fields
    @Override
    public OFInstructionType getType() {
        return OFInstructionType.METER;
    }

    @Override
    public long getMeterId() {
        return meterId;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



    public OFInstructionMeter.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFInstructionMeter.Builder {
        final OFInstructionMeterVer13 parentMessage;

        // OF message fields
        private boolean meterIdSet;
        private long meterId;

        BuilderWithParent(OFInstructionMeterVer13 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFInstructionType getType() {
        return OFInstructionType.METER;
    }

    @Override
    public long getMeterId() {
        return meterId;
    }

    @Override
    public OFInstructionMeter.Builder setMeterId(long meterId) {
        this.meterId = meterId;
        this.meterIdSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



        @Override
        public OFInstructionMeter build() {
                long meterId = this.meterIdSet ? this.meterId : parentMessage.meterId;

                //
                return new OFInstructionMeterVer13(
                    meterId
                );
        }

    }

    static class Builder implements OFInstructionMeter.Builder {
        // OF message fields
        private boolean meterIdSet;
        private long meterId;

    @Override
    public OFInstructionType getType() {
        return OFInstructionType.METER;
    }

    @Override
    public long getMeterId() {
        return meterId;
    }

    @Override
    public OFInstructionMeter.Builder setMeterId(long meterId) {
        this.meterId = meterId;
        this.meterIdSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

//
        @Override
        public OFInstructionMeter build() {
            long meterId = this.meterIdSet ? this.meterId : DEFAULT_METER_ID;


            return new OFInstructionMeterVer13(
                    meterId
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader extends AbstractOFMessageReader<OFInstructionMeter> {
        @Override
        public OFInstructionMeter readFrom(OFMessageReaderContext context, ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < LENGTH)
                return null;
            int start = bb.readerIndex();
            // fixed value property type == 6
            short type = bb.readShort();
            if(type != (short) 0x6)
                throw new OFParseError("Wrong type: Expected=OFInstructionType.METER(6), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 8)
                throw new OFParseError("Wrong length: Expected=8(8), got="+length);
            //
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            long meterId = U32.f(bb.readInt());

            OFInstructionMeterVer13 instructionMeterVer13 = new OFInstructionMeterVer13(
                    meterId
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", instructionMeterVer13);
            return instructionMeterVer13;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFInstructionMeterVer13Funnel FUNNEL = new OFInstructionMeterVer13Funnel();
    static class OFInstructionMeterVer13Funnel implements Funnel<OFInstructionMeterVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFInstructionMeterVer13 message, PrimitiveSink sink) {
            // fixed value property type = 6
            sink.putShort((short) 0x6);
            // fixed value property length = 8
            sink.putShort((short) 0x8);
            sink.putLong(message.meterId);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFInstructionMeterVer13> {
        @Override
        public void write(ByteBuf bb, OFInstructionMeterVer13 message) {
            // fixed value property type = 6
            bb.writeShort((short) 0x6);
            // fixed value property length = 8
            bb.writeShort((short) 0x8);
            bb.writeInt(U32.t(message.meterId));


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFInstructionMeterVer13(");
        b.append("meterId=").append(meterId);
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
        OFInstructionMeterVer13 other = (OFInstructionMeterVer13) obj;

        if( meterId != other.meterId)
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (meterId ^ (meterId >>> 32));
        return result;
    }

}
