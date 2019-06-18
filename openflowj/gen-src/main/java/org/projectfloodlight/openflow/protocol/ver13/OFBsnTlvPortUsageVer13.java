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

class OFBsnTlvPortUsageVer13 implements OFBsnTlvPortUsage {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnTlvPortUsageVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int LENGTH = 6;


    // OF message fields
    private final OFBsnPortUsage value;
//

    // package private constructor - used by readers, builders, and factory
    OFBsnTlvPortUsageVer13(OFBsnPortUsage value) {
        if(value == null) {
            throw new NullPointerException("OFBsnTlvPortUsageVer13: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public int getType() {
        return 0x8d;
    }

    @Override
    public OFBsnPortUsage getValue() {
        return value;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



    public OFBsnTlvPortUsage.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnTlvPortUsage.Builder {
        final OFBsnTlvPortUsageVer13 parentMessage;

        // OF message fields
        private boolean valueSet;
        private OFBsnPortUsage value;

        BuilderWithParent(OFBsnTlvPortUsageVer13 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public int getType() {
        return 0x8d;
    }

    @Override
    public OFBsnPortUsage getValue() {
        return value;
    }

    @Override
    public OFBsnTlvPortUsage.Builder setValue(OFBsnPortUsage value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



        @Override
        public OFBsnTlvPortUsage build() {
                OFBsnPortUsage value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFBsnTlvPortUsageVer13(
                    value
                );
        }

    }

    static class Builder implements OFBsnTlvPortUsage.Builder {
        // OF message fields
        private boolean valueSet;
        private OFBsnPortUsage value;

    @Override
    public int getType() {
        return 0x8d;
    }

    @Override
    public OFBsnPortUsage getValue() {
        return value;
    }

    @Override
    public OFBsnTlvPortUsage.Builder setValue(OFBsnPortUsage value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

//
        @Override
        public OFBsnTlvPortUsage build() {
            if(!this.valueSet)
                throw new IllegalStateException("Property value doesn't have default value -- must be set");
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFBsnTlvPortUsageVer13(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader extends AbstractOFMessageReader<OFBsnTlvPortUsage> {
        @Override
        public OFBsnTlvPortUsage readFrom(OFMessageReaderContext context, ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < LENGTH)
                return null;
            int start = bb.readerIndex();
            // fixed value property type == 0x8d
            short type = bb.readShort();
            if(type != (short) 0x8d)
                throw new OFParseError("Wrong type: Expected=0x8d(0x8d), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 6)
                throw new OFParseError("Wrong length: Expected=6(6), got="+length);
            //
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            OFBsnPortUsage value = OFBsnPortUsageSerializerVer13.readFrom(bb);

            OFBsnTlvPortUsageVer13 bsnTlvPortUsageVer13 = new OFBsnTlvPortUsageVer13(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnTlvPortUsageVer13);
            return bsnTlvPortUsageVer13;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnTlvPortUsageVer13Funnel FUNNEL = new OFBsnTlvPortUsageVer13Funnel();
    static class OFBsnTlvPortUsageVer13Funnel implements Funnel<OFBsnTlvPortUsageVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnTlvPortUsageVer13 message, PrimitiveSink sink) {
            // fixed value property type = 0x8d
            sink.putShort((short) 0x8d);
            // fixed value property length = 6
            sink.putShort((short) 0x6);
            OFBsnPortUsageSerializerVer13.putTo(message.value, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnTlvPortUsageVer13> {
        @Override
        public void write(ByteBuf bb, OFBsnTlvPortUsageVer13 message) {
            // fixed value property type = 0x8d
            bb.writeShort((short) 0x8d);
            // fixed value property length = 6
            bb.writeShort((short) 0x6);
            OFBsnPortUsageSerializerVer13.writeTo(bb, message.value);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnTlvPortUsageVer13(");
        b.append("value=").append(value);
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
        OFBsnTlvPortUsageVer13 other = (OFBsnTlvPortUsageVer13) obj;

        if (value == null) {
            if (other.value != null)
                return false;
        } else if (!value.equals(other.value))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((value == null) ? 0 : value.hashCode());
        return result;
    }

}
