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
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFActionMeterVer15 implements OFActionMeter {
    private static final Logger logger = LoggerFactory.getLogger(OFActionMeterVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 8;

        private final static long DEFAULT_METER_ID = 0x0L;

    // OF message fields
    private final long meterId;
//
    // Immutable default instance
    final static OFActionMeterVer15 DEFAULT = new OFActionMeterVer15(
        DEFAULT_METER_ID
    );

    // package private constructor - used by readers, builders, and factory
    OFActionMeterVer15(long meterId) {
        this.meterId = U32.normalize(meterId);
    }

    // Accessors for OF message fields
    @Override
    public long getMeterId() {
        return meterId;
    }

    @Override
    public OFActionType getType() {
        return OFActionType.METER;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFActionMeter.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFActionMeter.Builder {
        final OFActionMeterVer15 parentMessage;

        // OF message fields
        private boolean meterIdSet;
        private long meterId;

        BuilderWithParent(OFActionMeterVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getMeterId() {
        return meterId;
    }

    @Override
    public OFActionMeter.Builder setMeterId(long meterId) {
        this.meterId = meterId;
        this.meterIdSet = true;
        return this;
    }
    @Override
    public OFActionType getType() {
        return OFActionType.METER;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFActionMeter build() {
                long meterId = this.meterIdSet ? this.meterId : parentMessage.meterId;

                //
                return new OFActionMeterVer15(
                    meterId
                );
        }

    }

    static class Builder implements OFActionMeter.Builder {
        // OF message fields
        private boolean meterIdSet;
        private long meterId;

    @Override
    public long getMeterId() {
        return meterId;
    }

    @Override
    public OFActionMeter.Builder setMeterId(long meterId) {
        this.meterId = meterId;
        this.meterIdSet = true;
        return this;
    }
    @Override
    public OFActionType getType() {
        return OFActionType.METER;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFActionMeter build() {
            long meterId = this.meterIdSet ? this.meterId : DEFAULT_METER_ID;


            return new OFActionMeterVer15(
                    meterId
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFActionMeter> {
        @Override
        public OFActionMeter readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 29
            short type = bb.readShort();
            if(type != (short) 0x1d)
                throw new OFParseError("Wrong type: Expected=OFActionType.METER(29), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 8)
                throw new OFParseError("Wrong length: Expected=8(8), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            long meterId = U32.f(bb.readInt());

            OFActionMeterVer15 actionMeterVer15 = new OFActionMeterVer15(
                    meterId
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", actionMeterVer15);
            return actionMeterVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFActionMeterVer15Funnel FUNNEL = new OFActionMeterVer15Funnel();
    static class OFActionMeterVer15Funnel implements Funnel<OFActionMeterVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFActionMeterVer15 message, PrimitiveSink sink) {
            // fixed value property type = 29
            sink.putShort((short) 0x1d);
            // fixed value property length = 8
            sink.putShort((short) 0x8);
            sink.putLong(message.meterId);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFActionMeterVer15> {
        @Override
        public void write(ByteBuf bb, OFActionMeterVer15 message) {
            // fixed value property type = 29
            bb.writeShort((short) 0x1d);
            // fixed value property length = 8
            bb.writeShort((short) 0x8);
            bb.writeInt(U32.t(message.meterId));


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFActionMeterVer15(");
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
        OFActionMeterVer15 other = (OFActionMeterVer15) obj;

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
