// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver14;

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

class OFQueuePropMinRateVer14 implements OFQueuePropMinRate {
    private static final Logger logger = LoggerFactory.getLogger(OFQueuePropMinRateVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int LENGTH = 16;

        private final static int DEFAULT_RATE = 0x0;

    // OF message fields
    private final int rate;
//
    // Immutable default instance
    final static OFQueuePropMinRateVer14 DEFAULT = new OFQueuePropMinRateVer14(
        DEFAULT_RATE
    );

    // package private constructor - used by readers, builders, and factory
    OFQueuePropMinRateVer14(int rate) {
        this.rate = U16.normalize(rate);
    }

    // Accessors for OF message fields
    @Override
    public int getRate() {
        return rate;
    }

    @Override
    public int getType() {
        return 0x1;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



    public OFQueuePropMinRate.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFQueuePropMinRate.Builder {
        final OFQueuePropMinRateVer14 parentMessage;

        // OF message fields
        private boolean rateSet;
        private int rate;

        BuilderWithParent(OFQueuePropMinRateVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public int getRate() {
        return rate;
    }

    @Override
    public OFQueuePropMinRate.Builder setRate(int rate) {
        this.rate = rate;
        this.rateSet = true;
        return this;
    }
    @Override
    public int getType() {
        return 0x1;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



        @Override
        public OFQueuePropMinRate build() {
                int rate = this.rateSet ? this.rate : parentMessage.rate;

                //
                return new OFQueuePropMinRateVer14(
                    rate
                );
        }

    }

    static class Builder implements OFQueuePropMinRate.Builder {
        // OF message fields
        private boolean rateSet;
        private int rate;

    @Override
    public int getRate() {
        return rate;
    }

    @Override
    public OFQueuePropMinRate.Builder setRate(int rate) {
        this.rate = rate;
        this.rateSet = true;
        return this;
    }
    @Override
    public int getType() {
        return 0x1;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

//
        @Override
        public OFQueuePropMinRate build() {
            int rate = this.rateSet ? this.rate : DEFAULT_RATE;


            return new OFQueuePropMinRateVer14(
                    rate
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFQueuePropMinRate> {
        @Override
        public OFQueuePropMinRate readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 0x1
            short type = bb.readShort();
            if(type != (short) 0x1)
                throw new OFParseError("Wrong type: Expected=0x1(0x1), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 16)
                throw new OFParseError("Wrong length: Expected=16(16), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            // pad: 4 bytes
            bb.skipBytes(4);
            int rate = U16.f(bb.readShort());
            // pad: 6 bytes
            bb.skipBytes(6);

            OFQueuePropMinRateVer14 queuePropMinRateVer14 = new OFQueuePropMinRateVer14(
                    rate
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", queuePropMinRateVer14);
            return queuePropMinRateVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFQueuePropMinRateVer14Funnel FUNNEL = new OFQueuePropMinRateVer14Funnel();
    static class OFQueuePropMinRateVer14Funnel implements Funnel<OFQueuePropMinRateVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFQueuePropMinRateVer14 message, PrimitiveSink sink) {
            // fixed value property type = 0x1
            sink.putShort((short) 0x1);
            // fixed value property length = 16
            sink.putShort((short) 0x10);
            // skip pad (4 bytes)
            sink.putInt(message.rate);
            // skip pad (6 bytes)
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFQueuePropMinRateVer14> {
        @Override
        public void write(ByteBuf bb, OFQueuePropMinRateVer14 message) {
            // fixed value property type = 0x1
            bb.writeShort((short) 0x1);
            // fixed value property length = 16
            bb.writeShort((short) 0x10);
            // pad: 4 bytes
            bb.writeZero(4);
            bb.writeShort(U16.t(message.rate));
            // pad: 6 bytes
            bb.writeZero(6);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFQueuePropMinRateVer14(");
        b.append("rate=").append(rate);
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
        OFQueuePropMinRateVer14 other = (OFQueuePropMinRateVer14) obj;

        if( rate != other.rate)
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + rate;
        return result;
    }

}
