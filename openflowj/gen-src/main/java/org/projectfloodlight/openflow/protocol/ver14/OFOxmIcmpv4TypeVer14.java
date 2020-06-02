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

class OFOxmIcmpv4TypeVer14 implements OFOxmIcmpv4Type {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmIcmpv4TypeVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int LENGTH = 5;

        private final static ICMPv4Type DEFAULT_VALUE = ICMPv4Type.NONE;

    // OF message fields
    private final ICMPv4Type value;
//
    // Immutable default instance
    final static OFOxmIcmpv4TypeVer14 DEFAULT = new OFOxmIcmpv4TypeVer14(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmIcmpv4TypeVer14(ICMPv4Type value) {
        if(value == null) {
            throw new NullPointerException("OFOxmIcmpv4TypeVer14: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x80002601L;
    }

    @Override
    public ICMPv4Type getValue() {
        return value;
    }

    public OFOxm<ICMPv4Type> getCanonical() {
        // exact match OXM is always canonical
        return this;
    }

    @Override
    public ICMPv4Type getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.4");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<ICMPv4Type> getMatchField() {
        return MatchField.ICMPV4_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



    public OFOxmIcmpv4Type.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmIcmpv4Type.Builder {
        final OFOxmIcmpv4TypeVer14 parentMessage;

        // OF message fields
        private boolean valueSet;
        private ICMPv4Type value;

        BuilderWithParent(OFOxmIcmpv4TypeVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x80002601L;
    }

    @Override
    public ICMPv4Type getValue() {
        return value;
    }

    @Override
    public OFOxmIcmpv4Type.Builder setValue(ICMPv4Type value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<ICMPv4Type> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.4");
    }

    @Override
    public ICMPv4Type getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.4");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<ICMPv4Type> getMatchField() {
        return MatchField.ICMPV4_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



        @Override
        public OFOxmIcmpv4Type build() {
                ICMPv4Type value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFOxmIcmpv4TypeVer14(
                    value
                );
        }

    }

    static class Builder implements OFOxmIcmpv4Type.Builder {
        // OF message fields
        private boolean valueSet;
        private ICMPv4Type value;

    @Override
    public long getTypeLen() {
        return 0x80002601L;
    }

    @Override
    public ICMPv4Type getValue() {
        return value;
    }

    @Override
    public OFOxmIcmpv4Type.Builder setValue(ICMPv4Type value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<ICMPv4Type> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.4");
    }

    @Override
    public ICMPv4Type getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.4");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<ICMPv4Type> getMatchField() {
        return MatchField.ICMPV4_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

//
        @Override
        public OFOxmIcmpv4Type build() {
            ICMPv4Type value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFOxmIcmpv4TypeVer14(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmIcmpv4Type> {
        @Override
        public OFOxmIcmpv4Type readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x80002601L
            int typeLen = bb.readInt();
            if(typeLen != (int) 0x80002601)
                throw new OFParseError("Wrong typeLen: Expected=0x80002601L(0x80002601L), got="+typeLen);
            ICMPv4Type value = ICMPv4Type.readByte(bb);

            OFOxmIcmpv4TypeVer14 oxmIcmpv4TypeVer14 = new OFOxmIcmpv4TypeVer14(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmIcmpv4TypeVer14);
            return oxmIcmpv4TypeVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmIcmpv4TypeVer14Funnel FUNNEL = new OFOxmIcmpv4TypeVer14Funnel();
    static class OFOxmIcmpv4TypeVer14Funnel implements Funnel<OFOxmIcmpv4TypeVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmIcmpv4TypeVer14 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x80002601L
            sink.putInt((int) 0x80002601);
            message.value.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmIcmpv4TypeVer14> {
        @Override
        public void write(ByteBuf bb, OFOxmIcmpv4TypeVer14 message) {
            // fixed value property typeLen = 0x80002601L
            bb.writeInt((int) 0x80002601);
            message.value.writeByte(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmIcmpv4TypeVer14(");
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
        OFOxmIcmpv4TypeVer14 other = (OFOxmIcmpv4TypeVer14) obj;

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
