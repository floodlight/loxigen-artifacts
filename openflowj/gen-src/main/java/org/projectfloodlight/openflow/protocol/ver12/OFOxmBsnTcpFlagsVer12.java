// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver12;

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

class OFOxmBsnTcpFlagsVer12 implements OFOxmBsnTcpFlags {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmBsnTcpFlagsVer12.class);
    // version: 1.2
    final static byte WIRE_VERSION = 3;
    final static int LENGTH = 6;

        private final static U16 DEFAULT_VALUE = U16.ZERO;

    // OF message fields
    private final U16 value;
//
    // Immutable default instance
    final static OFOxmBsnTcpFlagsVer12 DEFAULT = new OFOxmBsnTcpFlagsVer12(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmBsnTcpFlagsVer12(U16 value) {
        if(value == null) {
            throw new NullPointerException("OFOxmBsnTcpFlagsVer12: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x32002L;
    }

    @Override
    public U16 getValue() {
        return value;
    }

    public OFOxm<U16> getCanonical() {
        // exact match OXM is always canonical
        return this;
    }

    @Override
    public U16 getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.2");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<U16> getMatchField() {
        return MatchField.BSN_TCP_FLAGS;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }



    public OFOxmBsnTcpFlags.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmBsnTcpFlags.Builder {
        final OFOxmBsnTcpFlagsVer12 parentMessage;

        // OF message fields
        private boolean valueSet;
        private U16 value;

        BuilderWithParent(OFOxmBsnTcpFlagsVer12 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x32002L;
    }

    @Override
    public U16 getValue() {
        return value;
    }

    @Override
    public OFOxmBsnTcpFlags.Builder setValue(U16 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<U16> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.2");
    }

    @Override
    public U16 getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.2");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<U16> getMatchField() {
        return MatchField.BSN_TCP_FLAGS;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }



        @Override
        public OFOxmBsnTcpFlags build() {
                U16 value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFOxmBsnTcpFlagsVer12(
                    value
                );
        }

    }

    static class Builder implements OFOxmBsnTcpFlags.Builder {
        // OF message fields
        private boolean valueSet;
        private U16 value;

    @Override
    public long getTypeLen() {
        return 0x32002L;
    }

    @Override
    public U16 getValue() {
        return value;
    }

    @Override
    public OFOxmBsnTcpFlags.Builder setValue(U16 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<U16> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.2");
    }

    @Override
    public U16 getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.2");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<U16> getMatchField() {
        return MatchField.BSN_TCP_FLAGS;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }

//
        @Override
        public OFOxmBsnTcpFlags build() {
            U16 value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFOxmBsnTcpFlagsVer12(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmBsnTcpFlags> {
        @Override
        public OFOxmBsnTcpFlags readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x32002L
            int typeLen = bb.readInt();
            if(typeLen != 0x32002)
                throw new OFParseError("Wrong typeLen: Expected=0x32002L(0x32002L), got="+typeLen);
            U16 value = U16.of(bb.readShort());

            OFOxmBsnTcpFlagsVer12 oxmBsnTcpFlagsVer12 = new OFOxmBsnTcpFlagsVer12(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmBsnTcpFlagsVer12);
            return oxmBsnTcpFlagsVer12;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmBsnTcpFlagsVer12Funnel FUNNEL = new OFOxmBsnTcpFlagsVer12Funnel();
    static class OFOxmBsnTcpFlagsVer12Funnel implements Funnel<OFOxmBsnTcpFlagsVer12> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmBsnTcpFlagsVer12 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x32002L
            sink.putInt(0x32002);
            message.value.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmBsnTcpFlagsVer12> {
        @Override
        public void write(ByteBuf bb, OFOxmBsnTcpFlagsVer12 message) {
            // fixed value property typeLen = 0x32002L
            bb.writeInt(0x32002);
            bb.writeShort(message.value.getRaw());


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmBsnTcpFlagsVer12(");
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
        OFOxmBsnTcpFlagsVer12 other = (OFOxmBsnTcpFlagsVer12) obj;

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
