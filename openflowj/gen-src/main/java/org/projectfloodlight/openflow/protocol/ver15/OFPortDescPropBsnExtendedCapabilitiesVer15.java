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

class OFPortDescPropBsnExtendedCapabilitiesVer15 implements OFPortDescPropBsnExtendedCapabilities {
    private static final Logger logger = LoggerFactory.getLogger(OFPortDescPropBsnExtendedCapabilitiesVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 44;

        private final static U64 DEFAULT_CONFIGURABILITY = U64.ZERO;
        private final static U64 DEFAULT_CONFLICT = U64.ZERO;
        private final static U64 DEFAULT_RESERVED1 = U64.ZERO;
        private final static U64 DEFAULT_RESERVED2 = U64.ZERO;

    // OF message fields
    private final U64 configurability;
    private final U64 conflict;
    private final U64 reserved1;
    private final U64 reserved2;
//
    // Immutable default instance
    final static OFPortDescPropBsnExtendedCapabilitiesVer15 DEFAULT = new OFPortDescPropBsnExtendedCapabilitiesVer15(
        DEFAULT_CONFIGURABILITY, DEFAULT_CONFLICT, DEFAULT_RESERVED1, DEFAULT_RESERVED2
    );

    // package private constructor - used by readers, builders, and factory
    OFPortDescPropBsnExtendedCapabilitiesVer15(U64 configurability, U64 conflict, U64 reserved1, U64 reserved2) {
        if(configurability == null) {
            throw new NullPointerException("OFPortDescPropBsnExtendedCapabilitiesVer15: property configurability cannot be null");
        }
        if(conflict == null) {
            throw new NullPointerException("OFPortDescPropBsnExtendedCapabilitiesVer15: property conflict cannot be null");
        }
        if(reserved1 == null) {
            throw new NullPointerException("OFPortDescPropBsnExtendedCapabilitiesVer15: property reserved1 cannot be null");
        }
        if(reserved2 == null) {
            throw new NullPointerException("OFPortDescPropBsnExtendedCapabilitiesVer15: property reserved2 cannot be null");
        }
        this.configurability = configurability;
        this.conflict = conflict;
        this.reserved1 = reserved1;
        this.reserved2 = reserved2;
    }

    // Accessors for OF message fields
    @Override
    public U64 getConfigurability() {
        return configurability;
    }

    @Override
    public U64 getConflict() {
        return conflict;
    }

    @Override
    public long getExpType() {
        return 0x8L;
    }

    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public U64 getReserved1() {
        return reserved1;
    }

    @Override
    public U64 getReserved2() {
        return reserved2;
    }

    @Override
    public int getType() {
        return 0xffff;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFPortDescPropBsnExtendedCapabilities.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFPortDescPropBsnExtendedCapabilities.Builder {
        final OFPortDescPropBsnExtendedCapabilitiesVer15 parentMessage;

        // OF message fields
        private boolean configurabilitySet;
        private U64 configurability;
        private boolean conflictSet;
        private U64 conflict;
        private boolean reserved1Set;
        private U64 reserved1;
        private boolean reserved2Set;
        private U64 reserved2;

        BuilderWithParent(OFPortDescPropBsnExtendedCapabilitiesVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public U64 getConfigurability() {
        return configurability;
    }

    @Override
    public OFPortDescPropBsnExtendedCapabilities.Builder setConfigurability(U64 configurability) {
        this.configurability = configurability;
        this.configurabilitySet = true;
        return this;
    }
    @Override
    public U64 getConflict() {
        return conflict;
    }

    @Override
    public OFPortDescPropBsnExtendedCapabilities.Builder setConflict(U64 conflict) {
        this.conflict = conflict;
        this.conflictSet = true;
        return this;
    }
    @Override
    public long getExpType() {
        return 0x8L;
    }

    @Override
    public OFPortDescPropBsnExtendedCapabilities.Builder setExpType(long expType) {
            throw new UnsupportedOperationException("Property expType is not writeable");
    }
    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public U64 getReserved1() {
        return reserved1;
    }

    @Override
    public OFPortDescPropBsnExtendedCapabilities.Builder setReserved1(U64 reserved1) {
        this.reserved1 = reserved1;
        this.reserved1Set = true;
        return this;
    }
    @Override
    public U64 getReserved2() {
        return reserved2;
    }

    @Override
    public OFPortDescPropBsnExtendedCapabilities.Builder setReserved2(U64 reserved2) {
        this.reserved2 = reserved2;
        this.reserved2Set = true;
        return this;
    }
    @Override
    public int getType() {
        return 0xffff;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFPortDescPropBsnExtendedCapabilities build() {
                U64 configurability = this.configurabilitySet ? this.configurability : parentMessage.configurability;
                if(configurability == null)
                    throw new NullPointerException("Property configurability must not be null");
                U64 conflict = this.conflictSet ? this.conflict : parentMessage.conflict;
                if(conflict == null)
                    throw new NullPointerException("Property conflict must not be null");
                U64 reserved1 = this.reserved1Set ? this.reserved1 : parentMessage.reserved1;
                if(reserved1 == null)
                    throw new NullPointerException("Property reserved1 must not be null");
                U64 reserved2 = this.reserved2Set ? this.reserved2 : parentMessage.reserved2;
                if(reserved2 == null)
                    throw new NullPointerException("Property reserved2 must not be null");

                //
                return new OFPortDescPropBsnExtendedCapabilitiesVer15(
                    configurability,
                    conflict,
                    reserved1,
                    reserved2
                );
        }

    }

    static class Builder implements OFPortDescPropBsnExtendedCapabilities.Builder {
        // OF message fields
        private boolean configurabilitySet;
        private U64 configurability;
        private boolean conflictSet;
        private U64 conflict;
        private boolean reserved1Set;
        private U64 reserved1;
        private boolean reserved2Set;
        private U64 reserved2;

    @Override
    public U64 getConfigurability() {
        return configurability;
    }

    @Override
    public OFPortDescPropBsnExtendedCapabilities.Builder setConfigurability(U64 configurability) {
        this.configurability = configurability;
        this.configurabilitySet = true;
        return this;
    }
    @Override
    public U64 getConflict() {
        return conflict;
    }

    @Override
    public OFPortDescPropBsnExtendedCapabilities.Builder setConflict(U64 conflict) {
        this.conflict = conflict;
        this.conflictSet = true;
        return this;
    }
    @Override
    public long getExpType() {
        return 0x8L;
    }

    @Override
    public OFPortDescPropBsnExtendedCapabilities.Builder setExpType(long expType) {
            throw new UnsupportedOperationException("Property expType is not writeable");
    }
    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public U64 getReserved1() {
        return reserved1;
    }

    @Override
    public OFPortDescPropBsnExtendedCapabilities.Builder setReserved1(U64 reserved1) {
        this.reserved1 = reserved1;
        this.reserved1Set = true;
        return this;
    }
    @Override
    public U64 getReserved2() {
        return reserved2;
    }

    @Override
    public OFPortDescPropBsnExtendedCapabilities.Builder setReserved2(U64 reserved2) {
        this.reserved2 = reserved2;
        this.reserved2Set = true;
        return this;
    }
    @Override
    public int getType() {
        return 0xffff;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFPortDescPropBsnExtendedCapabilities build() {
            U64 configurability = this.configurabilitySet ? this.configurability : DEFAULT_CONFIGURABILITY;
            if(configurability == null)
                throw new NullPointerException("Property configurability must not be null");
            U64 conflict = this.conflictSet ? this.conflict : DEFAULT_CONFLICT;
            if(conflict == null)
                throw new NullPointerException("Property conflict must not be null");
            U64 reserved1 = this.reserved1Set ? this.reserved1 : DEFAULT_RESERVED1;
            if(reserved1 == null)
                throw new NullPointerException("Property reserved1 must not be null");
            U64 reserved2 = this.reserved2Set ? this.reserved2 : DEFAULT_RESERVED2;
            if(reserved2 == null)
                throw new NullPointerException("Property reserved2 must not be null");


            return new OFPortDescPropBsnExtendedCapabilitiesVer15(
                    configurability,
                    conflict,
                    reserved1,
                    reserved2
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFPortDescPropBsnExtendedCapabilities> {
        @Override
        public OFPortDescPropBsnExtendedCapabilities readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 0xffff
            short type = bb.readShort();
            if(type != (short) 0xffff)
                throw new OFParseError("Wrong type: Expected=0xffff(0xffff), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 44)
                throw new OFParseError("Wrong length: Expected=44(44), got="+length);
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
            // fixed value property expType == 0x8L
            int expType = bb.readInt();
            if(expType != 0x8)
                throw new OFParseError("Wrong expType: Expected=0x8L(0x8L), got="+expType);
            U64 configurability = U64.ofRaw(bb.readLong());
            U64 conflict = U64.ofRaw(bb.readLong());
            U64 reserved1 = U64.ofRaw(bb.readLong());
            U64 reserved2 = U64.ofRaw(bb.readLong());

            OFPortDescPropBsnExtendedCapabilitiesVer15 portDescPropBsnExtendedCapabilitiesVer15 = new OFPortDescPropBsnExtendedCapabilitiesVer15(
                    configurability,
                      conflict,
                      reserved1,
                      reserved2
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", portDescPropBsnExtendedCapabilitiesVer15);
            return portDescPropBsnExtendedCapabilitiesVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFPortDescPropBsnExtendedCapabilitiesVer15Funnel FUNNEL = new OFPortDescPropBsnExtendedCapabilitiesVer15Funnel();
    static class OFPortDescPropBsnExtendedCapabilitiesVer15Funnel implements Funnel<OFPortDescPropBsnExtendedCapabilitiesVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFPortDescPropBsnExtendedCapabilitiesVer15 message, PrimitiveSink sink) {
            // fixed value property type = 0xffff
            sink.putShort((short) 0xffff);
            // fixed value property length = 44
            sink.putShort((short) 0x2c);
            // fixed value property experimenter = 0x5c16c7L
            sink.putInt(0x5c16c7);
            // fixed value property expType = 0x8L
            sink.putInt(0x8);
            message.configurability.putTo(sink);
            message.conflict.putTo(sink);
            message.reserved1.putTo(sink);
            message.reserved2.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFPortDescPropBsnExtendedCapabilitiesVer15> {
        @Override
        public void write(ByteBuf bb, OFPortDescPropBsnExtendedCapabilitiesVer15 message) {
            // fixed value property type = 0xffff
            bb.writeShort((short) 0xffff);
            // fixed value property length = 44
            bb.writeShort((short) 0x2c);
            // fixed value property experimenter = 0x5c16c7L
            bb.writeInt(0x5c16c7);
            // fixed value property expType = 0x8L
            bb.writeInt(0x8);
            bb.writeLong(message.configurability.getValue());
            bb.writeLong(message.conflict.getValue());
            bb.writeLong(message.reserved1.getValue());
            bb.writeLong(message.reserved2.getValue());


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFPortDescPropBsnExtendedCapabilitiesVer15(");
        b.append("configurability=").append(configurability);
        b.append(", ");
        b.append("conflict=").append(conflict);
        b.append(", ");
        b.append("reserved1=").append(reserved1);
        b.append(", ");
        b.append("reserved2=").append(reserved2);
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
        OFPortDescPropBsnExtendedCapabilitiesVer15 other = (OFPortDescPropBsnExtendedCapabilitiesVer15) obj;

        if (configurability == null) {
            if (other.configurability != null)
                return false;
        } else if (!configurability.equals(other.configurability))
            return false;
        if (conflict == null) {
            if (other.conflict != null)
                return false;
        } else if (!conflict.equals(other.conflict))
            return false;
        if (reserved1 == null) {
            if (other.reserved1 != null)
                return false;
        } else if (!reserved1.equals(other.reserved1))
            return false;
        if (reserved2 == null) {
            if (other.reserved2 != null)
                return false;
        } else if (!reserved2.equals(other.reserved2))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((configurability == null) ? 0 : configurability.hashCode());
        result = prime * result + ((conflict == null) ? 0 : conflict.hashCode());
        result = prime * result + ((reserved1 == null) ? 0 : reserved1.hashCode());
        result = prime * result + ((reserved2 == null) ? 0 : reserved2.hashCode());
        return result;
    }

}
