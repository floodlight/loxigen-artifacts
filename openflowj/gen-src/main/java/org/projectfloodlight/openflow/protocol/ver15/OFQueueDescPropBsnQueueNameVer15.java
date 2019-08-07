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
import java.util.Arrays;

class OFQueueDescPropBsnQueueNameVer15 implements OFQueueDescPropBsnQueueName {
    private static final Logger logger = LoggerFactory.getLogger(OFQueueDescPropBsnQueueNameVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int MINIMUM_LENGTH = 12;
    // maximum OF message length: 16 bit, unsigned
    final static int MAXIMUM_LENGTH = 0xFFFF;

        private final static byte[] DEFAULT_NAME = new byte[0];

    // OF message fields
    private final byte[] name;
//
    // Immutable default instance
    final static OFQueueDescPropBsnQueueNameVer15 DEFAULT = new OFQueueDescPropBsnQueueNameVer15(
        DEFAULT_NAME
    );

    // package private constructor - used by readers, builders, and factory
    OFQueueDescPropBsnQueueNameVer15(byte[] name) {
        if(name == null) {
            throw new NullPointerException("OFQueueDescPropBsnQueueNameVer15: property name cannot be null");
        }
        this.name = name;
    }

    // Accessors for OF message fields
    @Override
    public int getType() {
        return 0xffff;
    }

    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public long getExpType() {
        return 0x0L;
    }

    @Override
    public byte[] getName() {
        return name;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFQueueDescPropBsnQueueName.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFQueueDescPropBsnQueueName.Builder {
        final OFQueueDescPropBsnQueueNameVer15 parentMessage;

        // OF message fields
        private boolean nameSet;
        private byte[] name;

        BuilderWithParent(OFQueueDescPropBsnQueueNameVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public int getType() {
        return 0xffff;
    }

    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public long getExpType() {
        return 0x0L;
    }

    @Override
    public OFQueueDescPropBsnQueueName.Builder setExpType(long expType) {
            throw new UnsupportedOperationException("Property expType is not writeable");
    }
    @Override
    public byte[] getName() {
        return name;
    }

    @Override
    public OFQueueDescPropBsnQueueName.Builder setName(byte[] name) {
        this.name = name;
        this.nameSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFQueueDescPropBsnQueueName build() {
                byte[] name = this.nameSet ? this.name : parentMessage.name;
                if(name == null)
                    throw new NullPointerException("Property name must not be null");

                //
                return new OFQueueDescPropBsnQueueNameVer15(
                    name
                );
        }

    }

    static class Builder implements OFQueueDescPropBsnQueueName.Builder {
        // OF message fields
        private boolean nameSet;
        private byte[] name;

    @Override
    public int getType() {
        return 0xffff;
    }

    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public long getExpType() {
        return 0x0L;
    }

    @Override
    public OFQueueDescPropBsnQueueName.Builder setExpType(long expType) {
            throw new UnsupportedOperationException("Property expType is not writeable");
    }
    @Override
    public byte[] getName() {
        return name;
    }

    @Override
    public OFQueueDescPropBsnQueueName.Builder setName(byte[] name) {
        this.name = name;
        this.nameSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFQueueDescPropBsnQueueName build() {
            byte[] name = this.nameSet ? this.name : DEFAULT_NAME;
            if(name == null)
                throw new NullPointerException("Property name must not be null");


            return new OFQueueDescPropBsnQueueNameVer15(
                    name
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFQueueDescPropBsnQueueName> {
        @Override
        public OFQueueDescPropBsnQueueName readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 0xffff
            short type = bb.readShort();
            if(type != (short) 0xffff)
                throw new OFParseError("Wrong type: Expected=0xffff(0xffff), got="+type);
            int length = U16.f(bb.readShort());
            if(length < MINIMUM_LENGTH)
                throw new OFParseError("Wrong length: Expected to be >= " + MINIMUM_LENGTH + ", was: " + length);
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
            // fixed value property expType == 0x0L
            int expType = bb.readInt();
            if(expType != 0x0)
                throw new OFParseError("Wrong expType: Expected=0x0L(0x0L), got="+expType);
            byte[] name = ChannelUtils.readBytes(bb, length - (bb.readerIndex() - start));

            OFQueueDescPropBsnQueueNameVer15 queueDescPropBsnQueueNameVer15 = new OFQueueDescPropBsnQueueNameVer15(
                    name
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", queueDescPropBsnQueueNameVer15);
            return queueDescPropBsnQueueNameVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFQueueDescPropBsnQueueNameVer15Funnel FUNNEL = new OFQueueDescPropBsnQueueNameVer15Funnel();
    static class OFQueueDescPropBsnQueueNameVer15Funnel implements Funnel<OFQueueDescPropBsnQueueNameVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFQueueDescPropBsnQueueNameVer15 message, PrimitiveSink sink) {
            // fixed value property type = 0xffff
            sink.putShort((short) 0xffff);
            // FIXME: skip funnel of length
            // fixed value property experimenter = 0x5c16c7L
            sink.putInt(0x5c16c7);
            // fixed value property expType = 0x0L
            sink.putInt(0x0);
            sink.putBytes(message.name);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFQueueDescPropBsnQueueNameVer15> {
        @Override
        public void write(ByteBuf bb, OFQueueDescPropBsnQueueNameVer15 message) {
            int startIndex = bb.writerIndex();
            // fixed value property type = 0xffff
            bb.writeShort((short) 0xffff);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            // fixed value property experimenter = 0x5c16c7L
            bb.writeInt(0x5c16c7);
            // fixed value property expType = 0x0L
            bb.writeInt(0x0);
            bb.writeBytes(message.name);

            // update length field
            int length = bb.writerIndex() - startIndex;
            if (length > MAXIMUM_LENGTH) {
                throw new IllegalArgumentException("OFQueueDescPropBsnQueueNameVer15: message length (" + length + ") exceeds maximum (0xFFFF)");
            }
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFQueueDescPropBsnQueueNameVer15(");
        b.append("name=").append(Arrays.toString(name));
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
        OFQueueDescPropBsnQueueNameVer15 other = (OFQueueDescPropBsnQueueNameVer15) obj;

        if (!Arrays.equals(name, other.name))
                return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + Arrays.hashCode(name);
        return result;
    }

}
